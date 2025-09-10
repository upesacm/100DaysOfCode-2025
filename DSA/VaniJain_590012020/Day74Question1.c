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
void printNodesAtDistanceK(struct Node* root, int k) 
{
    if (root == NULL) return;
    if (k == 0) 
    {
        printf("%d ", root->data);
        return;
    }
    printNodesAtDistanceK(root->left, k - 1);
    printNodesAtDistanceK(root->right, k - 1);
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

int main() 
{
    printf("Build the binary tree:\n");
    struct Node* root = buildTree();
    int k;
    printf("Enter distance K from root: ");
    scanf("%d", &k);
    printf("Nodes at distance %d from root: ", k);
    printNodesAtDistanceK(root, k);
    printf("\n");
    return 0;
}
