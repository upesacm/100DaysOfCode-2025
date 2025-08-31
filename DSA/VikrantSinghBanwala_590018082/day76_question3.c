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

int countNodesAtLevel(Node* root, int level) {
    if (!root) return 0;
    if (level == 0) return 1;
    return countNodesAtLevel(root->left, level - 1) + countNodesAtLevel(root->right, level - 1);
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    int level = 2;
    int count = countNodesAtLevel(root, level);
    printf("%d\n", count);
    return 0;
}
