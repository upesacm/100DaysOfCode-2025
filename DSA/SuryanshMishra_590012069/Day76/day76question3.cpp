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
    int countNodesAtLevel(TreeNode* root, int level) {
        if (!root) return 0;
        return helper(root, level, 0);
    }
    
private:
    int helper(TreeNode* node, int targetLevel, int currentLevel) {
        if (!node) return 0;
        
        // If we reached the target level, count this node
        if (currentLevel == targetLevel) return 1;
        
        // Recursively count nodes at target level in left and right subtrees
        int leftCount = helper(node->left, targetLevel, currentLevel + 1);
        int rightCount = helper(node->right, targetLevel, currentLevel + 1);
        
        return leftCount + rightCount;
    }
};