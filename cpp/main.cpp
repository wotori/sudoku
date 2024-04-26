#include <iostream>
#include <vector>
#include <chrono>

bool is_valid(std::vector<std::vector<int>>& grid, int r, int c, int k) {
    for (int i = 0; i < 9; ++i) {
        if (grid[r][i] == k || grid[i][c] == k) {
            return false;
        }
    }

    int startRow = 3 * (r / 3);
    int startCol = 3 * (c / 3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[startRow + i][startCol + j] == k) {
                return false;
            }
        }
    }

    return true;
}

bool solve(std::vector<std::vector<int>>& grid, int r = 0, int c = 0) {
    if (r == 9) {
        return true;
    }
    if (c == 9) {
        return solve(grid, r + 1, 0);
    }
    if (grid[r][c] != 0) {
        return solve(grid, r, c + 1);
    }

    for (int k = 1; k <= 9; ++k) {
        if (is_valid(grid, r, c, k)) {
            grid[r][c] = k;
            if (solve(grid, r, c + 1)) {
                return true;
            }
            grid[r][c] = 0;
        }
    }

    return false;
}

int main() {
    std::vector<std::vector<int>> grid = {
        {2, 0, 0, 0, 8, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 7, 0, 0, 5},
        {4, 0, 9, 6, 0, 0, 0, 3, 0},
        {3, 0, 0, 0, 2, 0, 1, 0, 0},
        {0, 8, 0, 3, 0, 0, 0, 4, 0},
        {0, 1, 5, 0, 0, 0, 0, 0, 9},
        {0, 0, 0, 7, 0, 0, 8, 6, 0},
        {0, 0, 6, 0, 5, 0, 7, 0, 0},
        {0, 4, 0, 0, 0, 2, 0, 0, 0}
    };

    auto start = std::chrono::steady_clock::now();
    solve(grid);
    auto end = std::chrono::steady_clock::now();
    std::cout << "time taken: " << std::chrono::duration<double>(end - start).count() << " seconds" << std::endl;

    for (const auto& row : grid) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
