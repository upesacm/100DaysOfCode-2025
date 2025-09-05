#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

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

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    Node* root1 = newNode(4);
    root1->left = newNode(2);
    root1->right = newNode(6);
    root1->left->left = newNode(1);
    root1->left->right = newNode(3);
    root1->right->left = newNode(5);
    root1->right->right = newNode(7);
    printf("%s\n", isBalanced(root1) ? "Yes" : "No");

    Node* root2 = newNode(1);
    root2->right = newNode(2);
    root2->right->right = newNode(3);
    printf("%s\n", isBalanced(root2) ? "Yes" : "No");

    return 0;
}