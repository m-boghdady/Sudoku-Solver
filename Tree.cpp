// Tree.cpp
#include "Tree.h"
#include <iostream>


// TreeNode constructor
TreeNode::TreeNode(int val, TreeNode* parentNode) : value(val), parent(parentNode) {}

// Tree constructor
Tree::Tree() : root(nullptr), currentNode(nullptr) {}

// Tree destructor
Tree::~Tree() {
    deleteSubTree(root);
}

// Helper function to delete a subtree
void Tree::deleteSubTree(TreeNode* node) {
    if (node == nullptr) return;

    for (auto child : node->children) {
        deleteSubTree(child);
    }
    delete node;
}

// Add a new node to a specified parent node
bool Tree::addNode(int parentValue, int childValue) {
    if (root == nullptr && parentValue == -1) {
        root = new TreeNode(childValue);
        currentNode = root;
        return true;
    }

    TreeNode* parentNode = findNode(root, parentValue);
    if (parentNode != nullptr) {
        TreeNode* newNode = new TreeNode(childValue, parentNode);
        parentNode->children.push_back(newNode);
        return true;
    }
    return false;
}


// Add a new node to the current node
bool Tree::addNodeToCurrent(int childValue) {
    if (currentNode == nullptr) {
        return false; // Can't add a node if there's no current node
    }

    TreeNode* newNode = new TreeNode(childValue, currentNode);
    currentNode->children.push_back(newNode);
    return true;
}

// Find a node by value
TreeNode* Tree::findNode(TreeNode* node, int value) {
    if (node == nullptr) return nullptr;
    if (node->value == value) return node;

    for (auto child : node->children) {
        TreeNode* foundNode = findNode(child, value);
        if (foundNode != nullptr) return foundNode;
    }
    return nullptr;
}

// Delete a node by value
bool Tree::deleteNode(int value) {
    if (root == nullptr) return false;
    if (root->value == value) {
        deleteSubTree(root);
        root = nullptr;
        return true;
    }

    return deleteNodeHelper(root, value);
}

// Helper function to delete a node
bool Tree::deleteNodeHelper(TreeNode* parent, int value) {
    for (auto it = parent->children.begin(); it != parent->children.end(); ++it) {
        if ((*it)->value == value) {
            deleteSubTree(*it);
            parent->children.erase(it);
            return true;
        } else {
            if (deleteNodeHelper(*it, value)) return true;
        }
    }
    return false;
}

// Depth-first traversal
void Tree::depthFirstTraversal(TreeNode* node) {
    if (node == nullptr) return;

    cout << node->value << " ";
    for (auto child : node->children) {
        depthFirstTraversal(child);
    }
}

// Breadth-first traversal
void Tree::breadthFirstTraversal() {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node->value << " ";
        for (auto child : node->children) {
            q.push(child);
        }
    }
}

// Public function to start depth-first traversal
void Tree::displayDepthFirst() {
    depthFirstTraversal(root);
}

// Public function to start breadth-first traversal
void Tree::displayBreadthFirst() {
    breadthFirstTraversal();
}

// Traverse from a node to the root
void Tree::traverseToRoot(int value) {
    TreeNode* node = findNode(root, value);
    if (node == nullptr) {
        std::cout << "Node not found." << std::endl;
        return;
    }

    while (node != nullptr) {
        cout << node->value << " ";
        node = node->parent; // Move up to the parent
    }
    std::cout << std::endl;
}