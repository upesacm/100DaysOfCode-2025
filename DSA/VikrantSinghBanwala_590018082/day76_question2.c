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

int printAncestors(Node* root, int target) {
    if (!root) return 0;
    if (root->data == target) return 1;
    if (printAncestors(root->left, target) || printAncestors(root->right, target)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    int target = 4;
    printAncestors(root, target);
    return 0;
}
