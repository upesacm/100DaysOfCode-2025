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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int diameterUtil(struct Node* root, int* height) {
    if (root == NULL) {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ldiam = diameterUtil(root->left, &lh);
    int rdiam = diameterUtil(root->right, &rh);
    *height = max(lh, rh) + 1;
    return max(lh + rh + 1, max(ldiam, rdiam));
}

int diameter(struct Node* root) {
    int height = 0;
    return diameterUtil(root, &height);
}

int main() {
    struct Node* root = buildTree();
    printf("%d", diameter(root));
    return 0;
}
