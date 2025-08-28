#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}


int findMax(struct Node* root) {
    if (root == NULL) return INT_MIN;

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    int max = root->value;
    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;

    return max;
}

int main() {

    struct Node* root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);

    printf("Maximum value: %d\n", findMax(root));  
    return 0;
}

