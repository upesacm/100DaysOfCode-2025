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

int max(int a, int b) {
    return a > b ? a : b;
}

int height(struct Node* node) {
    if (node == NULL) return 0;
    return 1 + max(height(node->left), height(node->right));
}

int diameter(struct Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    return max(lh + rh, max(ld, rd));
}

struct Node* buildTree() {
    int x;
    scanf("%d", &x);
    if (x == -1) return NULL;
    struct Node* node = newNode(x);
    printf("Enter left child of %d (-1 for no child): ", x);
    node->left = buildTree();
    printf("Enter right child of %d (-1 for no child): ", x);
    node->right = buildTree();
    return node;
}

int main() {
    printf("Enter root value (-1 for no node): ");
    struct Node* root = buildTree();
    int d = diameter(root);
    printf("Diameter of Binary Tree: %d\n", d);
    return 0;
}
