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

int countLevelNodes(struct Node* root, int level) {
    if (!root) return 0;
    if (level == 0) return 1;
    return countLevelNodes(root->left, level - 1) + countLevelNodes(root->right, level - 1);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    int level;
    printf("Enter level to count nodes: ");
    scanf("%d", &level);

    int count = countLevelNodes(root, level);
    printf("Number of nodes at level %d: %d\n", level, count);
    return 0;
}
