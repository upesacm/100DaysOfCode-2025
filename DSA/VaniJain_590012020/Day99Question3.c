#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node 
{
    int val;
    struct Node *left, *right;
};
struct Node* newNode(int val) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
int maxPathSumUtil(struct Node* root, int *globalMax) 
{
    if (root == NULL) return 0;
    int left = maxPathSumUtil(root->left, globalMax);
    int right = maxPathSumUtil(root->right, globalMax);
    if (left < 0) left = 0;
    if (right < 0) right = 0;
    int localMax = left + right + root->val;
    if (localMax > *globalMax) 
    {
        *globalMax = localMax;
    }
    return root->val + (left > right ? left : right);
}
int maxPathSum(struct Node* root) 
{
    int globalMax = INT_MIN;
    maxPathSumUtil(root, &globalMax);
    return globalMax;
}
int main() 
{
    struct Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(10);
    root->left->left = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(4);
    int result = maxPathSum(root);
    printf("Maximum Path Sum = %d\n", result);
    return 0;
}
