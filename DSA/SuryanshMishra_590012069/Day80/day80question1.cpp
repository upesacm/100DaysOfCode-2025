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

// Iterative LCA for BST: uses BST ordering to find split point.
TreeNode* lowestCommonAncestorIter(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* cur = root;
    while (cur) {
        if (p->val < cur->val && q->val < cur->val) cur = cur->left;
        else if (p->val > cur->val && q->val > cur->val) cur = cur->right;
        else return cur; // split point
    }
    return nullptr;
}

// Recursive LCA for BST.
TreeNode* lowestCommonAncestorRec(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    if (p->val < root->val && q->val < root->val) return lowestCommonAncestorRec(root->left, p, q);
    if (p->val > root->val && q->val > root->val) return lowestCommonAncestorRec(root->right, p, q);
    return root;
}
