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
int maxDiameter = 0;
int height(struct Node* root) 
{
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int diameterThroughRoot = leftHeight + rightHeight;
    if (diameterThroughRoot > maxDiameter) 
    {
        maxDiameter = diameterThroughRoot;
    }
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
int findDiameter(struct Node* root) 
{
    maxDiameter = 0;
    height(root);
    return maxDiameter;
}
int main() 
{
    printf("Build the binary tree:\n");
    struct Node* root = buildTree();
    int diameter = findDiameter(root);
    printf("Diameter of the tree (in number of edges): %d\n", diameter);
    return 0;
}
