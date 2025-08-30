#include <cstddef>
#include <algorithm>
#include <functional>
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

// Returns diameter (number of nodes on longest path) of the tree.
int diameterOfBinaryTree(TreeNode* root) {
    int maxDiameter = 0;
    function<int(TreeNode*)> height = [&](TreeNode* node) -> int {
        if (!node) return 0;
        int lh = height(node->left);
        int rh = height(node->right);
    // diameter passing through node (number of nodes) equals lh + rh + 1
    maxDiameter = max(maxDiameter, lh + rh + 1);
        return max(lh, rh) + 1;
    };
    height(root);
    return maxDiameter;
}
