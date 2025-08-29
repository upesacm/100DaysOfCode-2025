#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* node, int* diameter) {
    if (node == NULL) return 0;

    int lh = height(node->left, diameter);
    int rh = height(node->right, diameter);

    *diameter = max(*diameter, lh + rh);

    return 1 + max(lh, rh);
}

int diameterOfTree(struct Node* root) {
    int diameter = 0;
    height(root, &diameter);
    return diameter;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Diameter of tree: %d\n", diameterOfTree(root));
    return 0;
}
