#include <vector>
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

// Recursive inorder traversal producing sorted order for BST.
void inorderHelper(TreeNode* node, vector<int>& out) {
    if (!node) return;
    inorderHelper(node->left, out);
    out.push_back(node->val);
    inorderHelper(node->right, out);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorderHelper(root, res);
    return res;
}
