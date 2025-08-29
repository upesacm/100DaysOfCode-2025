#include <cstddef>
#include <algorithm>
#include <climits>
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

// Recursive function to find maximum value in a binary tree. Assumes at least one node when called.
int findMax(TreeNode* root) {
    if (root == nullptr) return INT_MIN; // sentinel for empty subtree
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    return max(root->val, max(leftMax, rightMax));
}
