fn is_valid(grid: &Vec<Vec<i32>>, r: usize, c: usize, k: i32) -> bool {
    let not_in_row = !grid[r].contains(&k);
    let not_in_column = !(0..9).any(|i| grid[i][c] == k);
    let not_in_box = {
        let start_row = r / 3 * 3;
        let start_col = c / 3 * 3;
        !(start_row..start_row + 3).any(|i| (start_col..start_col + 3).any(|j| grid[i][j] == k))
    };
    not_in_row && not_in_column && not_in_box
}

fn solve(grid: &mut Vec<Vec<i32>>, r: usize, c: usize) -> bool {
    if r == 9 {
        return true;
    } else if c == 9 {
        return solve(grid, r + 1, 0);
    } else if grid[r][c] != 0 {
        return solve(grid, r, c + 1);
    } else {
        for k in 1..=9 {
            if is_valid(grid, r, c, k) {
                grid[r][c] = k;
                if solve(grid, r, c + 1) {
                    return true;
                }
                grid[r][c] = 0;
            }
        }
        false
    }
}

fn main() {
    let mut grid = vec![
        vec![2, 0, 0, 0, 8, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 7, 0, 0, 5],
        vec![4, 0, 9, 6, 0, 0, 0, 3, 0],
        vec![3, 0, 0, 0, 2, 0, 1, 0, 0],
        vec![0, 8, 0, 3, 0, 0, 0, 4, 0],
        vec![0, 1, 5, 0, 0, 0, 0, 0, 9],
        vec![0, 0, 0, 7, 0, 0, 8, 6, 0],
        vec![0, 0, 6, 0, 5, 0, 7, 0, 0],
        vec![0, 4, 0, 0, 0, 2, 0, 0, 0],
    ];

    let start_time = std::time::Instant::now();
    solve(&mut grid, 0, 0);
    let time_taken = start_time.elapsed().as_secs_f64();

    for row in grid {
        println!("{:?}", row);
    }
    println!("time taken: {}", time_taken);
}