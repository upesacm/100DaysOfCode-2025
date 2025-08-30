#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int toSumTree(struct Node* root) {
    if (!root) return 0;
    int old_val = root->data;
    root->data = toSumTree(root->left) + toSumTree(root->right);
    return root->data + old_val;
}

void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = createNode(10);
    root->left = createNode(-2);
    root->right = createNode(6);
    root->left->left = createNode(8);
    root->left->right = createNode(-4);
    root->right->left = createNode(7);
    root->right->right = createNode(5);

    toSumTree(root);
    inorder(root);
    return 0;
}
