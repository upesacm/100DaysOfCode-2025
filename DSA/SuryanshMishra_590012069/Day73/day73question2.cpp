#include <vector>
#include <queue>
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

// Level-order traversal using BFS; returns flattened list of node values in left-to-right, level-by-level order.
// Example: Input  [1,2,3] -> Output {1,2,3}
vector<int> levelOrder(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        res.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    return res;
}
