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

int findMax(struct Node* root) {
    if (root == NULL) return -1000000; // very small value
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    int max = root->data;
    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;
    return max;
}

int main() {
    // Example 1
    struct Node* root1 = newNode(3);
    root1->left = newNode(2);
    root1->right = newNode(5);
    printf("Max value: %d\n", findMax(root1)); // 5

    // Example 2
    struct Node* root2 = newNode(1);
    root2->right = newNode(9);
    printf("Max value: %d\n", findMax(root2)); // 9

    return 0;
}
