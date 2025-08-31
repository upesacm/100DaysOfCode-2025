#include <stdio.h>
#include <stdlib.h>


struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}


int sumOfNodes(struct Node* root) {
    if (root == NULL) return 0;
    return root->value + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main() {
    
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    printf("Sum of nodes: %d\n", sumOfNodes(root));  
    return 0;
}

