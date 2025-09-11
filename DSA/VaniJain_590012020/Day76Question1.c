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
int toSumTree(struct Node* root) 
{
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) 
    {
        int oldValue = root->data;
        root->data = 0;
        return oldValue;
    }
    int leftSum = toSumTree(root->left);
    int rightSum = toSumTree(root->right);
    int oldValue = root->data;
    root->data = leftSum + rightSum;
    return root->data + oldValue;
}
void inorder(struct Node* root) 
{
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main() 
{
    printf("Build the binary tree:\n");
    struct Node* root = buildTree();
    printf("\nOriginal Tree (Inorder): ");
    inorder(root);
    toSumTree(root);
    printf("\n\nSum Tree (Inorder): ");
    inorder(root);
    printf("\n");
    return 0;
}
