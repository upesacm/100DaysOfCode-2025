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

// Helper: find minimum node in a subtree (leftmost node).
TreeNode* findMin(TreeNode* node) {
    while (node && node->left) node = node->left;
    return node;
}

// Delete a node with value 'key' from BST and return new root.
// Uses inorder successor replacement for nodes with two children.
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Found node to delete
        if (root->left == nullptr) {
            TreeNode* r = root->right;
            // caller is responsible for freeing memory if desired
            return r;
        } else if (root->right == nullptr) {
            TreeNode* l = root->left;
            return l;
        } else {
            // Two children: replace value with inorder successor
            TreeNode* succ = findMin(root->right);
            root->val = succ->val;
            // Delete successor from right subtree
            root->right = deleteNode(root->right, succ->val);
        }
    }
    return root;
}
