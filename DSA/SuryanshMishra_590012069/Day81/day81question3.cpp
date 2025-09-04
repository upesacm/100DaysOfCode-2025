#include <vector>
#include <stack>
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

// Recursive pruned inorder traversal: collects node values within [L,R] in sorted order.
void rangeNodesHelper(TreeNode* node, int L, int R, vector<int>& out) {
    if (!node) return;
    if (node->val > L) rangeNodesHelper(node->left, L, R, out);
    if (node->val >= L && node->val <= R) out.push_back(node->val);
    if (node->val < R) rangeNodesHelper(node->right, L, R, out);
}

vector<int> rangeNodesRecursive(TreeNode* root, int L, int R) {
    vector<int> res;
    rangeNodesHelper(root, L, R, res);
    return res;
}

// Iterative pruned inorder using stack: efficiently skips irrelevant branches.
vector<int> rangeNodesIterative(TreeNode* root, int L, int R) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        while (cur) {
            // If current value is greater than L, left subtree may contain valid nodes
            if (cur->val > L) { st.push(cur); cur = cur->left; }
            else { // cur->val <= L: left subtree can't have nodes >= L
                break;
            }
        }
        if (st.empty()) {
            // handle the case where we broke out because cur->val <= L
            if (!cur) break;
        }
        if (!st.empty()) {
            cur = st.top(); st.pop();
            if (cur->val >= L && cur->val <= R) res.push_back(cur->val);
            // Move to right subtree if it may contain values <= R
            if (cur->val < R) cur = cur->right;
            else cur = nullptr;
        } else {
            // st empty but cur is set and cur->val <= L
            if (cur->val >= L && cur->val <= R) res.push_back(cur->val);
            if (cur->val < R) cur = cur->right;
            else cur = nullptr;
        }
    }
    return res;
}
