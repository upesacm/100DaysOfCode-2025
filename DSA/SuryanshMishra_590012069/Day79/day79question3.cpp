#include <cstddef>
#include <limits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Helper: validate node values are strictly between (low, high).
bool isValidBSTHelper(TreeNode* node, long long low, long long high) {
    if (node == nullptr) return true;
    if (node->val <= low || node->val >= high) return false;
    return isValidBSTHelper(node->left, low, node->val) &&
           isValidBSTHelper(node->right, node->val, high);
}

// Main API: returns true if tree is a valid BST.
bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root,
                            numeric_limits<long long>::lowest(),
                            numeric_limits<long long>::max());
}
