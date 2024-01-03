#include "SudokuSolver.h"

SudokuSolver::SudokuSolver() {
}

SudokuSolver::SudokuSolver(const vector<vector<int>>& initialBoard, int boardSize) : size(boardSize) {
    if (!initialBoard.empty()) {
        sudokuTree.currentNode = new SudokuBoardNode(initialBoard);
    }
}


bool SudokuSolver::solve(const vector<vector<int>>& initialBoard) {
    if (sudokuTree.currentNode == nullptr) {
        sudokuTree.currentNode = new SudokuBoardNode(initialBoard);
    }
    return solveBoard(sudokuTree.currentNode);
}


bool SudokuSolver::solveBoard(SudokuBoardNode* node) {

    // If there are no empty cells, check if the board is solved and valid
    int row, col;
    if (!findEmptyCell(node->board, row, col)) {
        if (isBoardValid(node->board)) {
            sudokuTree.currentNode = node;  // Update the current node to the solved board
            return true;
        }
        return false;
    }

    // Try placing each number in the empty cell and recurse
    for (int num = 1; num <= 9; num++) {
        if (isValidPlacement(node->board, row, col, num)) {
            vector<vector<int>> newBoard = node->board;  // Copy the current board
            newBoard[row][col] = num;  // Place the number

            // Create a new node for the tree and add it as a child
            SudokuBoardNode* childNode = new SudokuBoardNode(newBoard, node);
            node->children.push_back(childNode);

            // Recurse with the new board
            if (solveBoard(childNode)) {
                return true;  // Solution found, propagate the success back up the recursion
            }
            // If the number does not lead to a solution, the loop continues to try the next number
            // Backtracking is implicit as it moves to the next iteration, abandoning the current child node
        }
    }

    return false;  // No valid number found for the current empty cell, need to backtrack
}


bool SudokuSolver::findEmptyCell(const vector<vector<int>>& board, int& row, int& col) {
    for (row = 0; row < board.size(); row++) {
        for (col = 0; col < board[row].size(); col++) {
            if (board[row][col] == 0) { // 0 represents an empty cell
                return true;
            }
        }
    }
    return false; // No empty cell found
}

bool SudokuSolver::isValidPlacement(const vector<vector<int>>& board, int row, int col, int num) const {
    // Check the row
    for (int c = 0; c < size; c++) {
        if (board[row][c] == num) return false;
    }

    // Check the column
    for (int r = 0; r < size; r++) {
        if (board[r][col] == num) return false;
    }

    // Check the subgrid
    int subGridSize = subgridSize();
    int startRow = row - row % subGridSize;
    int startCol = col - col % subGridSize;
    for (int r = 0; r < subGridSize; r++) {
        for (int c = 0; c < subGridSize; c++) {
            if (board[startRow + r][startCol + c] == num) return false;
        }
    }

    return true;
}

bool SudokuSolver::isBoardComplete(const vector<vector<int>>& board) const {
    for (const auto& row : board) {
        for (int num : row) {
            if (num == 0) {
                return false; // If any cell is empty, the board is not complete
            }
        }
    }
    return true;
}

void SudokuSolver::showSolutionSteps()  {
    if (sudokuTree.currentNode == nullptr) {
        cout << "No solution found or not solved yet." << endl;
        return;
    }
    sudokuTree.backtrackAndShowBoards(sudokuTree.currentNode);
}

void SudokuSolver::displaySolution() const {
    if (sudokuTree.currentNode != nullptr) {
        sudokuTree.currentNode->showBoard();
    } else {
        cout << "No solution found or not solved yet." << endl;
    }
}
