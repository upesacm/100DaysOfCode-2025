#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int checkHeight(struct Node* root) {
    if (root == NULL) return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;

    if (abs(leftHeight - rightHeight) > 1) return -1;

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int isBalanced(struct Node* root) {
    return checkHeight(root) != -1;
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    if (isBalanced(root))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
