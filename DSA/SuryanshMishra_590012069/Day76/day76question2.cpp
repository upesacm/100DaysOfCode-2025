#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void printAncestors(TreeNode* root, int target) {
        helper(root, target);
    }
private:
    bool helper(TreeNode* node, int target) {
        if (!node) return false;
        if (node->val == target) return true;
        bool foundInLeft = helper(node->left, target);
        bool foundInRight = helper(node->right, target);
        if (foundInLeft || foundInRight) {
            std::cout << node->val << " ";
            return true;
        }
        
        return false;
    }
};