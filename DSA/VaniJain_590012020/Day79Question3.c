#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node 
{
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* buildTree() 
{
    int val;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d", &val);
    if (val == -1) return NULL;
    struct Node* root = createNode(val);
    printf("Enter left child of %d\n", val);
    root->left = buildTree();
    printf("Enter right child of %d\n", val);
    root->right = buildTree();
    return root;
}
int isValidBST(struct Node* root, int min, int max) 
{
    if (root == NULL) return 1;
    if (root->data <= min || root->data >= max)
        return 0;
    return isValidBST(root->left, min, root->data) &&
           isValidBST(root->right, root->data, max);
}
int main() 
{
    printf("Build the binary tree:\n");
    struct Node* root = buildTree();
    if (isValidBST(root, INT_MIN, INT_MAX))
        printf("The tree is a valid BST.\n");
    else
        printf("The tree is NOT a valid BST.\n");
    return 0;
}
