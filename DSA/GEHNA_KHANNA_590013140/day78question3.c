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

int findMin(struct Node* root) {
    while (root && root->left) root = root->left;
    return root ? root->data : -1;
}

int findMax(struct Node* root) {
    while (root && root->right) root = root->right;
    return root ? root->data : -1;
}

int main() {
    struct Node* root = buildTree();
    printf("Min = %d, Max = %d", findMin(root), findMax(root));
    return 0;
}
