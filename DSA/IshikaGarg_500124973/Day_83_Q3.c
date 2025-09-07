#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Store inorder traversal
void inorder(struct Node* root, int* arr, int* size) {
    if (!root) return;
    inorder(root->left, arr, size);
    arr[(*size)++] = root->val;
    inorder(root->right, arr, size);
}

int twoSumBST(struct Node* root, int target) {
    int arr[100], size = 0;
    inorder(root, arr, &size);

    int i = 0, j = size - 1;
    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == target) return 1;
        else if (sum < target) i++;
        else j--;
    }
    return 0;
}

int main() {
    struct Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->right = newNode(7);

    printf("Target 9: %s\n", twoSumBST(root, 9) ? "Yes" : "No");   // Expected Yes
    printf("Target 28: %s\n", twoSumBST(root, 28) ? "Yes" : "No"); // Expected No
    return 0;
}

