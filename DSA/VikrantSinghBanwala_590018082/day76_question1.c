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

int toSumTree(Node* root) {
    if (!root) return 0;
    int leftSum = toSumTree(root->left);
    int rightSum = toSumTree(root->right);
    int oldVal = root->data;
    root->data = leftSum + rightSum;
    return root->data + oldVal;
}

void printInOrder(Node* root) {
    if (!root) return;
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

int main() {
    Node* root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    toSumTree(root);

    printInOrder(root);
    return 0;
}
