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

void leftViewUtil(struct Node* root, int level, int *maxLevel) {
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
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(4);

    printf("Left View: ");
    leftView(root);
    printf("\n");
    return 0;
}
