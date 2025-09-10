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
struct Node* buildTree() 4
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
void printPath(int path[], int pathLen) 
{
    for (int i = 0; i < pathLen; i++) 
    {
        printf("%d ", path[i]);
    }
    printf("\n");
}
void printRootToLeafPaths(struct Node* root, int path[], int pathLen) 
{
    if (root == NULL) return;
    path[pathLen] = root->data;
    pathLen++;
    if (root->left == NULL && root->right == NULL) 
    {
        printPath(path, pathLen);
    } 
    else 
    {
        printRootToLeafPaths(root->left, path, pathLen);
        printRootToLeafPaths(root->right, path, pathLen);
    }
}
int main() 
{
    printf("Build the binary tree:\n");
    struct Node* root = buildTree();
    int path[1000]; 
    printf("Root-to-Leaf Paths:\n");
    printRootToLeafPaths(root, path, 0);
    return 0;
}
