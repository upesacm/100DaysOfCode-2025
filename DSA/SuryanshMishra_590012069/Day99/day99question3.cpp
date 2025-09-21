
#include <algorithm>
#include <climits>


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper for DFS
int dfs(TreeNode* node, int& maxSum) {
	if (!node) return 0;
	int left = std::max(0, dfs(node->left, maxSum));
	int right = std::max(0, dfs(node->right, maxSum));
	maxSum = std::max(maxSum, node->val + left + right);
	return node->val + std::max(left, right);
}

// Maximum Path Sum in Binary Tree (any node to any node)
int maxPathSum(TreeNode* root) {
	int maxSum = INT_MIN;
	dfs(root, maxSum);
	return maxSum;
}
