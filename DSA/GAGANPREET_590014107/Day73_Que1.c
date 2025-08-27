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

int sumOfNodes(Node* root) {
    if (root == NULL)
        return 0;
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main() {
    
    Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    printf("Sum of all nodes (Example 1): %d\n", sumOfNodes(root1));  

    
    Node* root2 = createNode(10);
    root2->left = createNode(5);
    printf("Sum of all nodes (Example 2): %d\n", sumOfNodes(root2));  

    
    free(root1->left);
    free(root1->right);
    free(root1);
    free(root2->left);
    free(root2);

    return 0;
}
