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
void inorder(struct Node* root) 
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main() 
{
    struct Node* root = NULL;
    int n, val, newValue;
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Inorder traversal before insertion: ");
    inorder(root);
    printf("\n");
    printf("Enter new value to insert: ");
    scanf("%d", &newValue);
    root = insert(root, newValue);
    printf("Inorder traversal after insertion: ");
    inorder(root);
    printf("\n");
    return 0;
}
