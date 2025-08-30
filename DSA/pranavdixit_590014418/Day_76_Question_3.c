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

int countNodesAtLevel(struct Node* root, int level) {
    if (root == NULL) return 0;
    if (level == 1) return 1;
    return countNodesAtLevel(root->left, level - 1) +
           countNodesAtLevel(root->right, level - 1);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    int level = 2;
    printf("Nodes at level %d: %d\n", level, countNodesAtLevel(root, level));
    return 0;
}
