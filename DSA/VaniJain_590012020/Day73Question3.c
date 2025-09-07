#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
int findMax(struct Node* root) 
{
    if (root == NULL)
        return INT_MIN;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    int max = root->data;
    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;
    return max;
}
int main() 
{
    struct Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(5);
    root->left->left = newNode(40);
    root->left->right = newNode(30);
    root->right->right = newNode(25);
    printf("Maximum value in the tree: %d\n", findMax(root));
    return 0;
}
