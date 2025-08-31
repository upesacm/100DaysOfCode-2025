#include <cstddef>
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

// Recursive function to compute sum of all node values in a binary tree.
long long sumOfNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    return root->val + sumOfNodes(root->left) + sumOfNodes(root->right);
}
