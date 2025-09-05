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

// Build height-balanced BST from sorted array using middle-element as root.
TreeNode* sortedArrayToBSTHelper(const vector<int>& nums, int l, int r) {
    if (l > r) return nullptr;
    int mid = l + (r - l) / 2;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = sortedArrayToBSTHelper(nums, l, mid - 1);
    node->right = sortedArrayToBSTHelper(nums, mid + 1, r);
    return node;
}

TreeNode* sortedArrayToBST(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    return sortedArrayToBSTHelper(nums, 0, (int)nums.size() - 1);
}

// Optional helper: preorder traversal to collect nodes for testing/verification.
void preorder(TreeNode* root, vector<int>& out) {
    if (!root) return;
    out.push_back(root->val);
    preorder(root->left, out);
    preorder(root->right, out);
}
