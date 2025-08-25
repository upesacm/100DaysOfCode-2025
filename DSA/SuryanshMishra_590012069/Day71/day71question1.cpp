#include <vector>
#include <stack>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive inorder traversal
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorderHelper(root, result);
    return result;
}

void inorderHelper(TreeNode* node, vector<int>& result) {
    if (node == nullptr) {
        return;
    }
    
    // Visit left subtree
    inorderHelper(node->left, result);
    
    // Visit current node
    result.push_back(node->val);
    
    // Visit right subtree
    inorderHelper(node->right, result);
}

// Iterative inorder traversal using stack
vector<int> inorderTraversalIterative(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> stk;
    TreeNode* current = root;
    
    while (current != nullptr || !stk.empty()) {
        // Go to leftmost node
        while (current != nullptr) {
            stk.push(current);
            current = current->left;
        }
        
        // Current is null, so we backtrack
        current = stk.top();
        stk.pop();
        result.push_back(current->val);
        
        // Move to right subtree
        current = current->right;
    }
    
    return result;
}

// Morris traversal (O(1) space complexity)
vector<int> inorderTraversalMorris(TreeNode* root) {
    vector<int> result;
    TreeNode* current = root;
    
    while (current != nullptr) {
        if (current->left == nullptr) {
            // No left subtree, visit current and go right
            result.push_back(current->val);
            current = current->right;
        } else {
            // Find inorder predecessor
            TreeNode* predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current) {
                predecessor = predecessor->right;
            }
            
            if (predecessor->right == nullptr) {
                // Create thread
                predecessor->right = current;
                current = current->left;
            } else {
                // Thread exists, remove it and visit current
                predecessor->right = nullptr;
                result.push_back(current->val);
                current = current->right;
            }
        }
    }
    
    return result;
}

// Print inorder traversal directly (without storing in vector)
void printInorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    printInorder(root->left);   // Left
    cout << root->val << " ";   // Root
    printInorder(root->right);  // Right
}

// Inorder traversal with level information
void inorderWithLevel(TreeNode* root, int level = 0) {
    if (root == nullptr) {
        return;
    }
    
    inorderWithLevel(root->left, level + 1);
    cout << "Level " << level << ": " << root->val << endl;
    inorderWithLevel(root->right, level + 1);
}

// Generic inorder traversal with custom function
template<typename Func>
void inorderTraversal(TreeNode* root, Func visit) {
    if (root == nullptr) {
        return;
    }
    
    inorderTraversal(root->left, visit);
    visit(root);
    inorderTraversal(root->right, visit);
}

// Validate BST using inorder traversal
bool isValidBST(TreeNode* root) {
    vector<int> inorder = inorderTraversal(root);
    
    for (int i = 1; i < inorder.size(); i++) {
        if (inorder[i] <= inorder[i-1]) {
            return false;
        }
    }
    return true;
}

// Alternative BST validation with single pass
bool isValidBSTSinglePass(TreeNode* root) {
    TreeNode* prev = nullptr;
    return isValidBSTHelper(root, prev);
}

bool isValidBSTHelper(TreeNode* node, TreeNode*& prev) {
    if (node == nullptr) {
        return true;
    }
    
    // Check left subtree
    if (!isValidBSTHelper(node->left, prev)) {
        return false;
    }
    
    // Check current node
    if (prev != nullptr && node->val <= prev->val) {
        return false;
    }
    prev = node;
    
    // Check right subtree
    return isValidBSTHelper(node->right, prev);
}
