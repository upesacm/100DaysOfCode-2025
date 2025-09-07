#include <stdio.h>
#include <stdlib.h>


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

void convertToGreaterTree(struct TreeNode* root, int* sum) {
    if (root == NULL)
        return;

    
    convertToGreaterTree(root->right, sum);

    
    *sum += root->val;
    root->val = *sum;

    
    convertToGreaterTree(root->left, sum);
}


void inorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}


int main() {
    
    struct TreeNode* root1 = newNode(5);
    root1->left = newNode(2);
    root1->right = newNode(13);

    int sum1 = 0;
    convertToGreaterTree(root1, &sum1);
    printf("Inorder Output for Tree 1: ");
    inorder(root1);
    printf("\n");

    
    struct TreeNode* root2 = newNode(2);
    root2->left = newNode(0);
    root2->right = newNode(3);
    root2->left->left = newNode(-4);
    root2->left->right = newNode(1);

    int sum2 = 0;
    convertToGreaterTree(root2, &sum2);
    printf("Inorder Output for Tree 2: ");
    inorder(root2);
    printf("\n");

    return 0;
}
