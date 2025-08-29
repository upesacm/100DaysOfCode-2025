#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int checkHeight(Node* root) {
    if (!root) return 0;
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;
    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;
    if (abs(leftHeight - rightHeight) > 1) return -1;
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

int main() {
    Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->left->left = newNode(3);

    if (isBalanced(root1)) printf("Yes\n");
    else printf("No\n");

    Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);

    if (isBalanced(root2)) printf("Yes\n");
    else printf("No\n");

    return 0;
}