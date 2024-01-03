// This is a modified version of the basic tree class to facilitate backtracking.

#include <vector>
#include <queue>
using namespace std;

// Define the Tree Node
struct TreeNode {
    int value;
    std::vector<TreeNode*> children;
    TreeNode* parent;  // Pointer to the parent node

    TreeNode(int val, TreeNode* parentNode = nullptr);
};

// Define the Tree Class
class Tree {
private:
    TreeNode* root;
    void deleteSubTree(TreeNode* node);
    TreeNode* findNode(TreeNode* node, int value);
    bool deleteNodeHelper(TreeNode* parent, int value);
    void depthFirstTraversal(TreeNode* node);
    void breadthFirstTraversal();


public:
    Tree();
    ~Tree(); 
    TreeNode* currentNode;
    bool addNode(int parentValue, int childValue);
    bool addNodeToCurrent(int childValue);
    bool deleteNode(int value);
    void displayDepthFirst();
    void displayBreadthFirst();
    void traverseToRoot(int value); 
    void setCurrentNode(TreeNode* node);  
    TreeNode* getCurrentNode() const; 
};
