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
struct Node* findLCA(struct Node* root, int n1, int n2) 
{
    if (root == NULL) return NULL;
    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);
    if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);
    return root;
}

int main() 
{
    struct Node* root = NULL;
    int n, val, n1, n2;
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter two node values to find LCA: ");
    scanf("%d %d", &n1, &n2);
    struct Node* lca = findLCA(root, n1, n2);
    if (lca != NULL)
        printf("Lowest Common Ancestor of %d and %d is: %d\n", n1, n2, lca->data);
    else
        printf("One or both nodes not present in the BST.\n");
    return 0;
}
