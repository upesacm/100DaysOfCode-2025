#include <cstddef>
#include <stack>
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

// Recursive pruned traversal: skip subtrees outside [L,R].
int rangeSumBSTRecursive(TreeNode* root, int L, int R) {
    if (root == nullptr) return 0;
    if (root->val < L) return rangeSumBSTRecursive(root->right, L, R);
    if (root->val > R) return rangeSumBSTRecursive(root->left, L, R);
    return root->val + rangeSumBSTRecursive(root->left, L, R) + rangeSumBSTRecursive(root->right, L, R);
}

// Iterative version using a stack and the same pruning logic.
int rangeSumBSTIterative(TreeNode* root, int L, int R) {
    if (root == nullptr) return 0;
    int sum = 0;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top(); st.pop();
        if (!node) continue;
        if (node->val < L) {
            st.push(node->right);
        } else if (node->val > R) {
            st.push(node->left);
        } else {
            sum += node->val;
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
    }
    return sum;
}
