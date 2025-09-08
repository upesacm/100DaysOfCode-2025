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
int sumOfNodes(struct Node* root) 
{
    if (root == NULL)
        return 0; 
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}
int main() 
{
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(2);
    root->left->right = newNode(7);
    printf("Sum of all nodes = %d\n", sumOfNodes(root));
    return 0;
}
