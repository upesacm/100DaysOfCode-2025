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
int count = 0;
struct Node* kthSmallest(struct Node* root, int K) 
{
    if (root == NULL) return NULL;
    struct Node* left = kthSmallest(root->left, K);
    if (left != NULL) return left;
    count++;
    if (count == K) return root;
    return kthSmallest(root->right, K);
}
int main() 
{
    struct Node* root = NULL;
    int n, val, K;
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter K to find Kth smallest element: ");
    scanf("%d", &K);
    struct Node* result = kthSmallest(root, K);
    if (result != NULL)
        printf("The %dth smallest element is: %d\n", K, result->data);
    else
        printf("K = %d is larger than number of nodes in BST.\n", K);
    return 0;
}
