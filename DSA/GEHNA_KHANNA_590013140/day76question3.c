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

int countLevel(struct Node* root, int level) {
    if (root == NULL) return 0;
    if (level == 1) return 1;
    return countLevel(root->left, level - 1) + countLevel(root->right, level - 1);
}

int main() {
    struct Node* root = buildTree();
    int level;
    scanf("%d", &level);
    printf("%d", countLevel(root, level));
    return 0;
}
