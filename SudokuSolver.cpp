//C++ program to solve a Sudoku using backtracking
#include <bits/stdc++.h> 
using namespace std; 

//Finds the unassigned cell (which contains 0)
bool FindUnassigned(int grid[9][9], int& row, int& col)
{
  for (row = 0; row < 9; row++) 
		for (col = 0; col < 9; col++) 
			if (grid[row][col] == 0) 
				return true; 
	return false; 
}

//Finds whether the num is used in any other cell in the row or not
bool UsedInRow(int grid[9][9], int row, int num) 
{ 
	for (int col = 0; col < 9; col++) 
		if (grid[row][col] == num) 
			return true; 
	return false; 
} 

//Finds whether the num is used in any other cell in the column or not
bool UsedInCol(int grid[9][9], int col, int num) 
{ 
	for (int row = 0; row < 9; row++) 
		if (grid[row][col] == num) 
			return true; 
	return false; 
} 

//Finds whether the num is used in any other cell in the 3x3 subgrid or not
bool UsedInBox(int grid[9][9], int subgridStartRow, int subgridStartCol, int num) 
{ 
	for (int row = 0; row < 3; row++) 
		for (int col = 0; col < 3; col++) 
			if (grid[row + subgridStartRow][col + subgridStartCol] == num)
				return true; 
	return false; 
} 


//Checks for the safety of the grid
bool isSafe(int grid[9][9], int row, int col, int num)
{
  return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - (row % 3), col - (col % 3), num) 
}

bool SudokuSolver(int grid[9][9]) 
{ 
	int row, col; 
  
	if (!FindUnassigned(grid, row, col)) 
		return true; 

	for (int num = 1; num <= 9; num++) { 
		if (isSafe(grid, row, col, num)) { 
			grid[row][col] = num; 
			if (SolveSudoku(grid)) 
				return true;
			grid[row][col] = 0; 
		} 
	} 
	// Triggers backtracking 
	return false; 
} 

//To print the grid
void print(int grid[9][9]) 
{ 
	for (int r = 0; r < 9; r++) { 
		for (int c = 0; c < 9; c++) 
			cout << grid[r][c] << " "; 
		cout << endl; 
	} 
} 

int main() 
{  
	int grid[9][9];
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      cin>>grid[i][j]; //Enter 0 for unassigned cells
  
	if (SudokuSolver(grid) == true) 
		print(grid); 
	else
		cout << "No solution"; 

	return 0; 
} 
