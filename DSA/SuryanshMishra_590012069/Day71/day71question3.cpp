#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive approach to find height/depth of binary tree
int maxDepth(TreeNode* root) {
    // Base case: empty tree has height 0
    if (root == nullptr) {
        return 0;
    }
    
    // Calculate height of left and right subtrees
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    
    // Return maximum height + 1 (for current node)
    return max(leftHeight, rightHeight) + 1;
}

// Alternative recursive implementation
int treeHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    
    return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

// Iterative approach using level-order traversal (BFS)
int maxDepthIterativeBFS(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    
    while (!q.empty()) {
        int levelSize = q.size();
        depth++; // Increment depth for each level
        
        // Process all nodes at current level
        for (int i = 0; i < levelSize; i++) {
            TreeNode* current = q.front();
            q.pop();
            
            // Add children to queue for next level
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }
    
    return depth;
}

// Iterative approach using DFS with stack (stores node with its depth)
int maxDepthIterativeDFS(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    
    stack<pair<TreeNode*, int>> stk; // {node, depth}
    stk.push({root, 1});
    int maxDepth = 0;
    
    while (!stk.empty()) {
        pair<TreeNode*, int> current = stk.top();
        stk.pop();
        TreeNode* node = current.first;
        int depth = current.second;
        
        // Update maximum depth
        maxDepth = max(maxDepth, depth);
        
        // Add children with incremented depth
        if (node->left != nullptr) {
            stk.push({node->left, depth + 1});
        }
        if (node->right != nullptr) {
            stk.push({node->right, depth + 1});
        }
    }
    
    return maxDepth;
}

// Find minimum depth (shortest path to a leaf)
int minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    
    // If one subtree is empty, take the other
    if (root->left == nullptr) {
        return minDepth(root->right) + 1;
    }
    if (root->right == nullptr) {
        return minDepth(root->left) + 1;
    }
    
    // Both subtrees exist, take minimum
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

// Check if tree is balanced (heights of subtrees differ by at most 1)
bool isBalanced(TreeNode* root) {
    return checkBalance(root) != -1;
}

int checkBalance(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    
    int leftHeight = checkBalance(node->left);
    if (leftHeight == -1) return -1; // Left subtree unbalanced
    
    int rightHeight = checkBalance(node->right);
    if (rightHeight == -1) return -1; // Right subtree unbalanced
    
    // Check if current node maintains balance
    if (abs(leftHeight - rightHeight) > 1) {
        return -1; // Unbalanced
    }
    
    return max(leftHeight, rightHeight) + 1;
}

// Find depth of a specific node value
int findDepth(TreeNode* root, int target) {
    return findDepthHelper(root, target, 1);
}

int findDepthHelper(TreeNode* node, int target, int currentDepth) {
    if (node == nullptr) {
        return -1; // Not found
    }
    
    if (node->val == target) {
        return currentDepth;
    }
    
    // Search in left subtree
    int leftResult = findDepthHelper(node->left, target, currentDepth + 1);
    if (leftResult != -1) {
        return leftResult;
    }
    
    // Search in right subtree
    return findDepthHelper(node->right, target, currentDepth + 1);
}

// Get all nodes at a specific depth
vector<int> getNodesAtDepth(TreeNode* root, int targetDepth) {
    vector<int> result;
    getNodesAtDepthHelper(root, targetDepth, 1, result);
    return result;
}

void getNodesAtDepthHelper(TreeNode* node, int targetDepth, int currentDepth, vector<int>& result) {
    if (node == nullptr) {
        return;
    }
    
    if (currentDepth == targetDepth) {
        result.push_back(node->val);
        return;
    }
    
    // Recurse to next level
    getNodesAtDepthHelper(node->left, targetDepth, currentDepth + 1, result);
    getNodesAtDepthHelper(node->right, targetDepth, currentDepth + 1, result);
}

// Calculate tree diameter (longest path between any two nodes)
int diameter(TreeNode* root) {
    int maxDiameter = 0;
    diameterHelper(root, maxDiameter);
    return maxDiameter;
}

int diameterHelper(TreeNode* node, int& maxDiameter) {
    if (node == nullptr) {
        return 0;
    }
    
    int leftHeight = diameterHelper(node->left, maxDiameter);
    int rightHeight = diameterHelper(node->right, maxDiameter);
    
    // Update diameter (path through current node)
    maxDiameter = max(maxDiameter, leftHeight + rightHeight);
    
    // Return height of current subtree
    return max(leftHeight, rightHeight) + 1;
}

// Count total number of nodes (using height calculation principle)
int countNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Calculate sum of all depths of nodes
int sumOfDepths(TreeNode* root) {
    return sumOfDepthsHelper(root, 1);
}

int sumOfDepthsHelper(TreeNode* node, int depth) {
    if (node == nullptr) {
        return 0;
    }
    
    return depth + 
           sumOfDepthsHelper(node->left, depth + 1) + 
           sumOfDepthsHelper(node->right, depth + 1);
}

// Check if tree has specific height
bool hasHeight(TreeNode* root, int targetHeight) {
    return maxDepth(root) == targetHeight;
}
