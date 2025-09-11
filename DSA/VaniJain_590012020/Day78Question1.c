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
int search(struct Node* root, int key) 
{
    if (root == NULL)
        return 0; 
    if (root->data == key)
        return 1; 
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key); 
}
int main() 
{
    struct Node* root = NULL;
    int n, val, key;
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter key to search: ");
    scanf("%d", &key);
    if (search(root, key))
        printf("Key %d exists in the BST.\n", key);
    else
        printf("Key %d does not exist in the BST.\n", key);
    return 0;
}
