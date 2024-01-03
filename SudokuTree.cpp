#include "SudokuTree.h"


// SudokuBoardNode constructor
SudokuBoardNode::SudokuBoardNode(const vector<vector<int>>& boardState, SudokuBoardNode* parentNode)
    : board(boardState), parent(parentNode) {}

// SudokuTree constructor
SudokuTree::SudokuTree() : root(nullptr) {}

// SudokuTree destructor
SudokuTree::~SudokuTree() {
    deleteSubTree(root);
}

void SudokuTree::deleteSubTree(SudokuBoardNode* node) {
    if (node == nullptr) return;

    for (auto child : node->children) {
        deleteSubTree(child);
    }
    delete node;
}

bool SudokuTree::addBoard(const vector<vector<int>>& childBoard) {
    if ( currentNode == nullptr) {
        // If there is no current node, create the root
        root = new SudokuBoardNode(childBoard);
        currentNode = root;
        return true;
    }

    // Create a new child node and add it to the current node's children
    SudokuBoardNode* childNode = new SudokuBoardNode(childBoard, currentNode);
    currentNode->children.push_back(childNode);
    return true;
}


void SudokuTree::backtrackAndShowBoards(SudokuBoardNode* currentNode) {
    while (currentNode != nullptr) {
        currentNode->showBoard(); // Display the current board using the node's method
        currentNode = currentNode->parent; // Move to the parent node
    }
}

