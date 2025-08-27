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

int findMax(struct Node* root) {
    if (!root) return -2147483648;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    int max = root->data;
    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;
    return max;
}

int main() {
    struct Node* root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    printf("%d\n", findMax(root));
    return 0;
}
