#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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


bool printAncestors(Node* root, int target) {
    if (root == NULL)
        return false;

    
    if (root->data == target)
        return true;

    
    if (printAncestors(root->left, target) || printAncestors(root->right, target)) {
        printf("%d ", root->data);  
        return true;
    }

    return false;
}

int main() {
   

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    int target = 4;
    printf("Ancestors of node %d: ", target);
    printAncestors(root, target);
    printf("\n");

    
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
