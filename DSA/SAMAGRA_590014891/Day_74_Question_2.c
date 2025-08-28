#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int height(struct Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int isBalanced(struct Node* root) {
    if (root == NULL) return 1;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1) return 0;
    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(3);

    if (isBalanced(root))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
