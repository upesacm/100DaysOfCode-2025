#include <stdio.h>
#include <stdlib.h>
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
struct Node* insert(struct Node* root, int value)
{
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}
int findMin(struct Node* root) 
{
    if (root == NULL) 
    {
        printf("Tree is empty!\n");
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}
int findMax(struct Node* root) 
{
    if (root == NULL) 
    {
        printf("Tree is empty!\n");
        return -1;
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}
int main() 
{
    struct Node* root = NULL;
    int n, val;
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    int minVal = findMin(root);
    int maxVal = findMax(root);
    if (root != NULL) 
    {
        printf("Minimum value in BST: %d\n", minVal);
        printf("Maximum value in BST: %d\n", maxVal);
    }
    return 0;
}
