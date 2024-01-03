#include "Tree.h"
#include <vector>
#include <iostream>
using namespace std;

// Define the Sudoku Board Node
struct SudokuBoardNode {
    vector<vector<int>> board;  // 2D vector for the Sudoku board
    SudokuBoardNode* parent;    // Pointer to the parent node
    vector<SudokuBoardNode*> children; // Children nodes

    SudokuBoardNode(const vector<vector<int>>& boardState, SudokuBoardNode* parentNode = nullptr);

    void showBoard() const 
    {
    for (const auto& row : board) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << "------------------" << endl; 
    } ;  // Method to display the board
};




// Define the Sudoku Tree Class
class SudokuTree : public Tree {
private:
    SudokuBoardNode* root;
    void deleteSubTree(SudokuBoardNode* node);


public:
    SudokuTree();
    ~SudokuTree(); 
    SudokuBoardNode* currentNode;
    bool addBoard(const vector<vector<int>>& childBoard);
    void backtrackAndShowBoards(SudokuBoardNode* currentNode);
};
