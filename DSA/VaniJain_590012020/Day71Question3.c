#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
int height(struct Node* root) 
{
    if (root == NULL)
        return 0; 
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
int main() 
{
    struct Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(7);
    int h = height(root);
    printf("Height of the tree: %d\n", h);
    return 0;
}
