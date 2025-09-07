#include <cstddef>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

// Definition for a binary search tree node (matching project convention).
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Approach 1: Inorder -> sorted array, then two-pointer scan (O(n) time, O(n) space).
bool findTargetTwoPointer(TreeNode* root, int k) {
    if (!root) return false;
    vector<int> vals;
    // iterative inorder
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        while (cur) { st.push(cur); cur = cur->left; }
        cur = st.top(); st.pop();
        vals.push_back(cur->val);
        cur = cur->right;
    }

    int i = 0, j = (int)vals.size() - 1;
    while (i < j) {
        long long s = (long long)vals[i] + vals[j];
        if (s == k) return true;
        if (s < k) ++i; else --j;
    }
    return false;
}

// Approach 2: For each node, search the BST for (k - node->val) while excluding the same node.
// This avoids building a full vector but is usually O(n log n) average time.
static bool searchWithExclude(TreeNode* root, int target, TreeNode* exclude) {
    TreeNode* cur = root;
    while (cur) {
        if (cur->val == target) return cur != exclude;
        if (target < cur->val) cur = cur->left; else cur = cur->right;
    }
    return false;
}

bool findTargetBSTSearch(TreeNode* root, int k) {
    if (!root) return false;
    // inorder traversal and for each node search complement
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        while (cur) { st.push(cur); cur = cur->left; }
        cur = st.top(); st.pop();
        int comp = k - cur->val;
        if (searchWithExclude(root, comp, cur)) return true;
        cur = cur->right;
    }
    return false;
}

// Default helper: expose a simple API (uses two-pointer approach by default).
bool twoSumInBST(TreeNode* root, int target) {
    return findTargetTwoPointer(root, target);
}
