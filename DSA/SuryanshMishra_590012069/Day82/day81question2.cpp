#include <cstddef>
#include <algorithm>
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

// Returns -1 if unbalanced, otherwise returns height.
int heightOrUnbalanced(TreeNode* node) {
    if (!node) return 0;
    int lh = heightOrUnbalanced(node->left);
    if (lh == -1) return -1;
    int rh = heightOrUnbalanced(node->right);
    if (rh == -1) return -1;
    if (abs(lh - rh) > 1) return -1;
    return max(lh, rh) + 1;
}

bool isBalanced(TreeNode* root) {
    return heightOrUnbalanced(root) != -1;
}
