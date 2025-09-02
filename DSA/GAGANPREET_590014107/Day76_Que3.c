#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


int countNodesAtLevel(Node* root, int level) {
    if (root == NULL)
        return 0;

    if (level == 1)
        return 1;

    
    return countNodesAtLevel(root->left, level - 1) +
           countNodesAtLevel(root->right, level - 1);
}


int main() {
    
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    int targetLevel = 2;
    int count = countNodesAtLevel(root, targetLevel);
    printf("Number of nodes at level %d: %d\n", targetLevel, count);

    
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
