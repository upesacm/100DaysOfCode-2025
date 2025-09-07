#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}


int checkHeight(struct TreeNode* root, bool* isBalanced) {
    if (root == NULL)
        return 0;

    int leftHeight = checkHeight(root->left, isBalanced);
    int rightHeight = checkHeight(root->right, isBalanced);

    if (abs(leftHeight - rightHeight) > 1)
        *isBalanced = false;

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isTreeBalanced(struct TreeNode* root) {
    bool isBalanced = true;
    checkHeight(root, &isBalanced);
    return isBalanced;
}

int main() {
    
    struct TreeNode* root1 = newNode(4);
    root1->left = newNode(2);
    root1->right = newNode(6);
    root1->left->left = newNode(1);
    root1->left->right = newNode(3);
    root1->right->left = newNode(5);
    root1->right->right = newNode(7);

    printf("Tree 1 is %s\n", isTreeBalanced(root1) ? "Balanced" : "Not Balanced");

    
    struct TreeNode* root2 = newNode(1);
    root2->right = newNode(2);
    root2->right->right = newNode(3);

    printf("Tree 2 is %s\n", isTreeBalanced(root2) ? "Balanced" : "Not Balanced");

    return 0;
}
