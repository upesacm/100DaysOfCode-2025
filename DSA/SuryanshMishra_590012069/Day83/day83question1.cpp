#include <vector>
#include <queue>
#include <map>
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

// Vertical order traversal (BFS) grouping nodes by horizontal distance (column).
// Uses BFS so nodes are added top-to-bottom and left-to-right within the same row.
vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    map<int, vector<int>> cols; // ordered by column index
    queue<pair<TreeNode*, int>> q; // node with its column index
    q.push({root, 0});

    while (!q.empty()) {
        auto front = q.front(); q.pop();
        TreeNode* node = front.first;
        int col = front.second;
        cols[col].push_back(node->val);
        if (node->left) q.push({node->left, col - 1});
        if (node->right) q.push({node->right, col + 1});
    }

    for (auto &p : cols) result.push_back(p.second);
    return result;
}
