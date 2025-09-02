#include <cstddef>
using namespace std;

// Definition for a binary search tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive BST search: returns true if target exists.
bool searchBSTRecursive(TreeNode* root, int target) {
    if (root == nullptr) return false;
    if (root->val == target) return true;
    if (target < root->val) return searchBSTRecursive(root->left, target);
    return searchBSTRecursive(root->right, target);
}

// Iterative BST search.
bool searchBSTIterative(TreeNode* root, int target) {
    TreeNode* cur = root;
    while (cur) {
        if (cur->val == target) return true;
        cur = (target < cur->val) ? cur->left : cur->right;
    }
    return false;
}
