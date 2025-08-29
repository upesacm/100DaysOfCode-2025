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

void printNodesAtK(Node* root, int K) {
    if (!root) return;
    if (K == 0) {
        printf("%d ", root->data);
        return;
    }
    printNodesAtK(root->left, K - 1);
    printNodesAtK(root->right, K - 1);
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int K = 2;
    printNodesAtK(root, K);
    return 0;
}