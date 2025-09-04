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

void leftViewUtil(struct Node* root, int level, int* maxLevel) {
    if (root == NULL) return;
    if (*maxLevel < level) {
        printf("%d ", root->data);
        *maxLevel = level;
    }
    leftViewUtil(root->left, level + 1, maxLevel);
    leftViewUtil(root->right, level + 1, maxLevel);
}

void leftView(struct Node* root) {
    int maxLevel = 0;
    leftViewUtil(root, 1, &maxLevel);
}

int main() {
    struct Node* root = buildTree();
    leftView(root);
    return 0;
}
