#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree() {
    int val;
    if (scanf("%d", &val) != 1 || val == -1) return NULL;
    struct Node* root = newNode(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int toSumTree(struct Node* root) {
    if (root == NULL) return 0;
    int old_val = root->data;
    root->data = toSumTree(root->left) + toSumTree(root->right);
    return root->data + old_val;
}

void printPreorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    struct Node* root = buildTree();
    toSumTree(root);
    printPreorder(root);
    return 0;
}
