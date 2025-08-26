#include <vector>
#include <queue>
#include <stack>
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

// Recursive approach to count leaf nodes
int countLeaves(TreeNode* root) {
    // Base case: empty tree has no leaves
    if (root == nullptr) {
        return 0;
    }
    
    // Check if current node is a leaf
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    
    // Recursively count leaves in left and right subtrees
    return countLeaves(root->left) + countLeaves(root->right);
}

// Iterative approach using level-order traversal (BFS)
int countLeavesIterativeBFS(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    int leafCount = 0;
    
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        
        // Check if current node is a leaf
        if (current->left == nullptr && current->right == nullptr) {
            leafCount++;
        } else {
            // Add children to queue
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }
    
    return leafCount;
}

// Iterative approach using depth-first traversal (DFS with stack)
int countLeavesIterativeDFS(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    
    stack<TreeNode*> stk;
    stk.push(root);
    int leafCount = 0;
    
    while (!stk.empty()) {
        TreeNode* current = stk.top();
        stk.pop();
        
        // Check if current node is a leaf
        if (current->left == nullptr && current->right == nullptr) {
            leafCount++;
        } else {
            // Add children to stack
            if (current->right != nullptr) {
                stk.push(current->right);
            }
            if (current->left != nullptr) {
                stk.push(current->left);
            }
        }
    }
    
    return leafCount;
}

// Count leaves and collect their values
pair<int, vector<int>> countAndCollectLeaves(TreeNode* root) {
    vector<int> leafValues;
    int count = countAndCollectHelper(root, leafValues);
    return {count, leafValues};
}

int countAndCollectHelper(TreeNode* node, vector<int>& leafValues) {
    if (node == nullptr) {
        return 0;
    }
    
    // Check if current node is a leaf
    if (node->left == nullptr && node->right == nullptr) {
        leafValues.push_back(node->val);
        return 1;
    }
    
    // Recursively process subtrees
    return countAndCollectHelper(node->left, leafValues) + 
           countAndCollectHelper(node->right, leafValues);
}

// Count leaves at a specific level
int countLeavesAtLevel(TreeNode* root, int targetLevel) {
    return countLeavesAtLevelHelper(root, targetLevel, 0);
}

int countLeavesAtLevelHelper(TreeNode* node, int targetLevel, int currentLevel) {
    if (node == nullptr) {
        return 0;
    }
    
    // If we've reached the target level
    if (currentLevel == targetLevel) {
        // Check if this node is a leaf
        return (node->left == nullptr && node->right == nullptr) ? 1 : 0;
    }
    
    // Recursively check next level
    return countLeavesAtLevelHelper(node->left, targetLevel, currentLevel + 1) +
           countLeavesAtLevelHelper(node->right, targetLevel, currentLevel + 1);
}

// Count leaves with values in a specific range
int countLeavesInRange(TreeNode* root, int minVal, int maxVal) {
    if (root == nullptr) {
        return 0;
    }
    
    // Check if current node is a leaf and in range
    if (root->left == nullptr && root->right == nullptr) {
        return (root->val >= minVal && root->val <= maxVal) ? 1 : 0;
    }
    
    // Recursively count in subtrees
    return countLeavesInRange(root->left, minVal, maxVal) + 
           countLeavesInRange(root->right, minVal, maxVal);
}

// Get depth of each leaf node
vector<pair<int, int>> getLeafDepths(TreeNode* root) {
    vector<pair<int, int>> leafDepths; // {value, depth}
    getLeafDepthsHelper(root, 0, leafDepths);
    return leafDepths;
}

void getLeafDepthsHelper(TreeNode* node, int depth, vector<pair<int, int>>& leafDepths) {
    if (node == nullptr) {
        return;
    }
    
    // Check if current node is a leaf
    if (node->left == nullptr && node->right == nullptr) {
        leafDepths.push_back({node->val, depth});
        return;
    }
    
    // Recursively process children
    getLeafDepthsHelper(node->left, depth + 1, leafDepths);
    getLeafDepthsHelper(node->right, depth + 1, leafDepths);
}

// Check if all leaves are at the same level
bool areAllLeavesAtSameLevel(TreeNode* root) {
    int firstLeafLevel = -1;
    return checkLeafLevels(root, 0, firstLeafLevel);
}

bool checkLeafLevels(TreeNode* node, int currentLevel, int& firstLeafLevel) {
    if (node == nullptr) {
        return true;
    }
    
    // If this is a leaf
    if (node->left == nullptr && node->right == nullptr) {
        if (firstLeafLevel == -1) {
            firstLeafLevel = currentLevel; // First leaf found
            return true;
        }
        return currentLevel == firstLeafLevel; // Check if same level
    }
    
    // Recursively check both subtrees
    return checkLeafLevels(node->left, currentLevel + 1, firstLeafLevel) &&
           checkLeafLevels(node->right, currentLevel + 1, firstLeafLevel);
}

// Count internal nodes (non-leaf nodes)
int countInternalNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    
    // If it's a leaf, it's not internal
    if (root->left == nullptr && root->right == nullptr) {
        return 0;
    }
    
    // It's an internal node, count it and recurse
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}
