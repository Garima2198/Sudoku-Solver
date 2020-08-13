# Sudoku-Solver
A C++ program to solve a given sudoku using backtracking algorithm 

A partially filed sudoku (9x9 matrix) is given as an input to the program. The output of the program is a solved sudoku, that is, a 9x9 matrix such that every row, column, and subgrid of size 3×3 contains exactly one instance of the digits from 1 to 9.

*Algorithm:*
1) A function SudokuSolver() is created which takes the grid as the input. It first checks for an unassigned location (using the FindUnassigned() function), if not present, returns true.
2) If an unassigned location is present, it assigns a number from 1-9 and checks for the safety of the grid after the assignment using isSafe() function. A grid will be safe if it contains exactly one instance of a digit from 1-9 in every row, column and subgrid of size 3x3. 
3) If the grid is safe, it recursively calls itself for all other unassigned locations. If any recursive call returns false, the tentative assignment is removed (backtacking) and other numbers are tried for the unassigned location similarly. If all the digits have been tried, and nothing works, false is returned (No solution). 
4) If there is no unassigned location found, that means the grid is solved and true is returned. 

