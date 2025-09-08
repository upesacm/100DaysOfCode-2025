#include <cstddef>
#include <stack>
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

// Recursive reverse-inorder conversion: each node becomes node + sum of greater nodes.
TreeNode* convertBSTRecursive(TreeNode* root) {
    long long acc = 0;
    // helper defined as lambda capturing acc by reference
    function<void(TreeNode*)> dfs = [&](TreeNode* node) {
        if (!node) return;
        dfs(node->right);
        acc += node->val;
        node->val = (int)acc;
        dfs(node->left);
    };
    dfs(root);
    return root;
}

// Iterative reverse-inorder conversion using a stack.
TreeNode* convertBSTIterative(TreeNode* root) {
    long long acc = 0;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        while (cur) { st.push(cur); cur = cur->right; }
        cur = st.top(); st.pop();
        acc += cur->val;
        cur->val = (int)acc;
        cur = cur->left;
    }
    return root;
}
