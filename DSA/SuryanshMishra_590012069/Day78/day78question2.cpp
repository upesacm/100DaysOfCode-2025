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

// Recursive insertion into BST. Returns new root.
TreeNode* insertIntoBSTRecursive(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);
    if (val < root->val) root->left = insertIntoBSTRecursive(root->left, val);
    else root->right = insertIntoBSTRecursive(root->right, val);
    return root;
}

// Iterative insertion into BST.
TreeNode* insertIntoBSTIterative(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);
    TreeNode* cur = root;
    while (true) {
        if (val < cur->val) {
            if (cur->left) cur = cur->left;
            else { cur->left = new TreeNode(val); break; }
        } else {
            if (cur->right) cur = cur->right;
            else { cur->right = new TreeNode(val); break; }
        }
    }
    return root;
}
