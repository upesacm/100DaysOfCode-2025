#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;


TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}


int maxSum = -1000000;


int maxPath(TreeNode* root) {
    if (root == NULL) return 0;

    
    int left = maxPath(root->left);
    int right = maxPath(root->right);

    
    if (left < 0) left = 0;
    if (right < 0) right = 0;

   
    int currentSum = root->val + left + right;
    if (currentSum > maxSum) {
        maxSum = currentSum;
    }

    
    return root->val + (left > right ? left : right);
}

int main() {
    
    TreeNode* root1 = newNode(10);
    root1->left = newNode(2);
    root1->right = newNode(10);
    root1->left->left = newNode(20);
    root1->left->right = newNode(1);
    root1->right->right = newNode(-25);
    root1->right->right->left = newNode(3);
    root1->right->right->right = newNode(4);

    maxSum = -1000000;
    maxPath(root1);
    printf("Maximum Path Sum (Example 1): %d\n", maxSum); 
    
    TreeNode* root2 = newNode(-10);
    root2->left = newNode(9);
    root2->right = newNode(20);
    root2->right->left = newNode(15);
    root2->right->right = newNode(7);

    maxSum = -1000000;
    maxPath(root2);
    printf("Maximum Path Sum (Example 2): %d\n", maxSum); 

    return 0;
}