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
void inorder(struct Node* root) 
{
    if (root == NULL)
        return;
    inorder(root->left);      
    printf("%d ", root->data); 
    inorder(root->right);      
}
int main() 
{
    struct Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
    return 0;
}
