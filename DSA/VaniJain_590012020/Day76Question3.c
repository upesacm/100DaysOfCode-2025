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
int countNodesAtLevel(struct Node* root, int level) 
{
    if (root == NULL) return 0;
    if (level == 0) return 1;
    return countNodesAtLevel(root->left, level - 1) +
           countNodesAtLevel(root->right, level - 1);
}
int main() 
{
    printf("Build the binary tree:\n");
    struct Node* root = buildTree();
    int targetLevel;
    printf("Enter target level (root is level 0): ");
    scanf("%d", &targetLevel);
    int count = countNodesAtLevel(root, targetLevel);
    printf("Number of nodes at level %d: %d\n", targetLevel, count);
    return 0;
}
