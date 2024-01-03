#include "SudokuSolver.h"
#include <iostream>
#include <vector>

using namespace std;

// Function to read a Sudoku board from user input
vector<vector<int>> readSudokuBoard(int size) {
    vector<vector<int>> board(size, vector<int>(size));
    cout << "Enter the Sudoku puzzle (use 0 for empty cells):" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> board[i][j];
        }
    }
    return board;
}

int main() {
    int size = 9;  // Standard Sudoku size
    cout << "Welcome to the Sudoku Solver!" << endl;
    auto board = readSudokuBoard(size);

    SudokuSolver solver(board, size);

    cout << "Solving the Sudoku..." << endl;
    if (solver.solve(board)) {
        cout << "Solved Sudoku:" << endl;
        solver.displaySolution();

        // Optionally show the solution steps
        char showSteps;
        cout << "Do you want to see the solution steps? (y/n): ";
        cin >> showSteps;
        if (showSteps == 'y' || showSteps == 'Y') {
            solver.showSolutionSteps();
        }
    } else {
        cout << "No solution found for the given Sudoku." << endl;
    }

    return 0;
}
