# sudo-vs-ku

This is an experimental project investigating the solving of Sudoku puzzles and comparing the speed performance between C++, Rust, and Python.
Based on Python implementation from this [source](https://gist.github.com/syphh/62e6140361feb2d7196f2cb050c987b3). 

# Compilation Instructions
C++
```
g++ -std=c++11 sudoku.cpp -o sudoku
```

Rust
```
cargo build --release
```

# Execution Time Comparison
Language | Execution Time
-------- | --------------
Rust     | 0.00086270 seconds
C++      | 0.00203462 seconds
Python   | 0.03006958 seconds