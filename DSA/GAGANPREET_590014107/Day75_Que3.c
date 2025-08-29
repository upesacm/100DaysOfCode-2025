#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int diameterUtil(Node* root, int* diameter) {
    if (!root) return 0;
    int leftHeight = diameterUtil(root->left, diameter);
    int rightHeight = diameterUtil(root->right, diameter);
    int pathLength = leftHeight + rightHeight + 1;
    if (pathLength > *diameter) *diameter = pathLength;
    return max(leftHeight, rightHeight) + 1;
}

int diameter(Node* root) {
    int diameter = 0;
    diameterUtil(root, &diameter);
    return diameter - 1;
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("%d\n", diameter(root));
    return 0;
}
