#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        std::vector<int> sortedNodes;
        inorderTraversal(root, sortedNodes);

        int left = 0;
        int right = sortedNodes.size() - 1;

        while (left < right) {
            int current_sum = sortedNodes[left] + sortedNodes[right];
            if (current_sum == k) return true;
            if (current_sum < k) left++;
            else right--;
        }
        return false;
    }

private:
    void inorderTraversal(TreeNode* root, std::vector<int>& nodes) {
        if (!root) return;
        inorderTraversal(root->left, nodes);
        nodes.push_back(root->val);
        inorderTraversal(root->right, nodes);
    }
};

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);

    Solution sol;
    int target1 = 9;
    std::cout << "Tree Inorder: 2 3 4 5 6 7" << std::endl;
    std::cout << "Target = " << target1 << ": " << (sol.findTarget(root, target1) ? "Yes" : "No") << std::endl;

    int target2 = 28;
    std::cout << "Target = " << target2 << ": " << (sol.findTarget(root, target2) ? "Yes" : "No") << std::endl;
    
    return 0;
}