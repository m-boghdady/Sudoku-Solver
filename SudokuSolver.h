#include "SudokuTree.h" 
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class SudokuSolver {
private:
    SudokuTree sudokuTree;
    int size; 
    int subgridSize() const { return sqrt(size); }  
    bool solveBoard(SudokuBoardNode* node);
    bool isBoardValid(const vector<vector<int>>& board) const;
    bool isBoardComplete(const vector<vector<int>>& board) const;
    bool isValidPlacement(const vector<vector<int>>& board, int row, int col, int num) const;
    bool findEmptyCell(const vector<vector<int>>& board, int& row, int& col);
    vector<vector<int>> findNextBoards(const vector<vector<int>>& board) const;
    
public:
    SudokuSolver();
    SudokuSolver(const vector<vector<int>>& initialBoard = vector<vector<int>>(), int boardSize = 9);
    bool solve(const vector<vector<int>>& initialBoard);
    void displaySolution() const;
    void showSolutionSteps();
};


