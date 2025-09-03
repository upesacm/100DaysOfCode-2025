#include <stack>
#include <cstddef>
using namespace std;

// Definition for a binary search tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Iterative inorder approach to find k-th smallest in BST (O(h + k) time).
int kthSmallestIter(TreeNode* root, int k) {
    stack<TreeNode*> st;
    TreeNode* cur = root;
    int count = 0;
    while (cur || !st.empty()) {
        while (cur) { st.push(cur); cur = cur->left; }
        cur = st.top(); st.pop();
        ++count;
        if (count == k) return cur->val;
        cur = cur->right;
    }
    return -1; // k is out of bounds
}

// Recursive inorder with counter (stops early when k reaches 0).
void kthHelper(TreeNode* node, int &k, int &result) {
    if (!node || k == 0) return;
    kthHelper(node->left, k, result);
    if (k == 0) return;
    --k;
    if (k == 0) { result = node->val; return; }
    kthHelper(node->right, k, result);
}

int kthSmallestRec(TreeNode* root, int k) {
    int result = -1;
    kthHelper(root, k, result);
    return result;
}
