#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
bool printAncestors(struct Node* root, int target) 
{
    if (root == NULL) return false;
    if (root->data == target) return true;
    if (printAncestors(root->left, target) || printAncestors(root->right, target)) 
    {
        printf("%d ", root->data);  
        return true;
    }
    return false;
}
int main() 
{
    printf("Build the binary tree:\n");
    struct Node* root = buildTree();
    int target;
    printf("Enter target node value: ");
    scanf("%d", &target);
    printf("Ancestors of %d: ", target);
    if (!printAncestors(root, target)) 
    {
        printf("Node not found in the tree.");
    }
    printf("\n");
    return 0;
}
