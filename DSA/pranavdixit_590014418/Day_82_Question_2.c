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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int checkHeight(struct Node* root) {
    if (root == NULL) return 0;

    int lh = checkHeight(root->left);
    if (lh == -1) return -1;

    int rh = checkHeight(root->right);
    if (rh == -1) return -1;

    if (abs(lh - rh) > 1) return -1;

    return max(lh, rh) + 1;
}

int isBalanced(struct Node* root) {
    return checkHeight(root) != -1;
}

int main() {
    struct Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);

    if (isBalanced(root))
        printf("Yes\n");
    else
        printf("No\n");

    struct Node* skewed = newNode(1);
    skewed->right = newNode(2);
    skewed->right->right = newNode(3);

    if (isBalanced(skewed))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
