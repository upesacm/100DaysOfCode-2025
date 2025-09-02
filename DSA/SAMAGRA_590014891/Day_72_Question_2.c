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

int isIdentical(struct Node* a, struct Node* b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;
    return (a->data == b->data) && isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
}

int main() {
    struct Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);

    struct Node* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);

    if (isIdentical(root1, root2)) printf("Yes");
    else printf("No");
    return 0;
}
