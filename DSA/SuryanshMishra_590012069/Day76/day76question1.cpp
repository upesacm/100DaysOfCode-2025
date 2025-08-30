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
    void convertToSumTree(TreeNode* root) {
        helper(root);
    }  
private:
    int helper(TreeNode* node) {
        if (!node) return 0;
        
        int oldVal = node->val;        
        int leftSum = helper(node->left);
        int rightSum = helper(node->right);        
        node->val = leftSum + rightSum;        
        return oldVal + leftSum + rightSum;
    }
};