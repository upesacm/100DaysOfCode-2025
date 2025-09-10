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
void printRange(struct Node* root, int L, int R) 
{
    if (root == NULL) return;
    if (root->data > L)
        printRange(root->left, L, R);
    if (root->data >= L && root->data <= R)
        printf("%d ", root->data);
    if (root->data < R)
        printRange(root->right, L, R);
}
int main() 
{
    struct Node* root = NULL;
    int n, val, L, R;
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter range [L R]: ");
    scanf("%d %d", &L, &R);
    printf("Nodes within range [%d, %d]: ", L, R);
    printRange(root, L, R);
    printf("\n");
    return 0;
}
