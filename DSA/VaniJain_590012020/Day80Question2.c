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
struct Node* findMin(struct Node* root) 
{
    while (root->left != NULL)
        root = root->left;
    return root;
}
struct Node* deleteNode(struct Node* root, int key) 
{
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else 
    {
        if (root->left == NULL && root->right == NULL) 
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) 
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) 
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
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
    int n, val, key;
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Inorder traversal before deletion: ");
    inorder(root);
    printf("\n");
    printf("Enter value to delete: ");
    scanf("%d", &key);
    root = deleteNode(root, key);
    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");
    return 0;
}
