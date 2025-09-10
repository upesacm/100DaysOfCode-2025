#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
int checkHeight(struct Node* root, bool *isBalanced) 
{
    if (root == NULL) return 0;
    int leftHeight = checkHeight(root->left, isBalanced);
    int rightHeight = checkHeight(root->right, isBalanced);
    if (abs(leftHeight - rightHeight) > 1) 
    {
        *isBalanced = false;
    }
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
bool isBalancedTree(struct Node* root) 
{
    bool isBalanced = true;
    checkHeight(root, &isBalanced);
    return isBalanced;
}
int main() 
{
    printf("Build the binary tree:\n");
    struct Node* root = buildTree();
    if (isBalancedTree(root)) 
    {
        printf("The tree is balanced.\n");
    } 
    else 
    {
        printf("The tree is NOT balanced.\n");
    }
    return 0;
}
