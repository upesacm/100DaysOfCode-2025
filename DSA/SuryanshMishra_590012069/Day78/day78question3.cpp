#include <cstddef>
#include <climits>
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

// Find minimum value in a BST (leftmost node). Returns INT_MAX for empty tree.
int findMinBST(TreeNode* root) {
    if (root == nullptr) return INT_MAX;
    TreeNode* cur = root;
    while (cur->left) cur = cur->left;
    return cur->val;
}

// Find maximum value in a BST (rightmost node). Returns INT_MIN for empty tree.
int findMaxBST(TreeNode* root) {
    if (root == nullptr) return INT_MIN;
    TreeNode* cur = root;
    while (cur->right) cur = cur->right;
    return cur->val;
}
