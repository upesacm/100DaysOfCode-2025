#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node* buildBST(int* arr, int start, int end) {
    if (start > end) return NULL;
    int mid = start + (end - start) / 2;
    Node* root = (Node*)malloc(sizeof(Node));
    root->val = arr[mid];
    root->left = buildBST(arr, start, mid - 1);
    root->right = buildBST(arr, mid + 1, end);
    return root;
}

void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    Node* root1 = buildBST(arr1, 0, n1 - 1);
    preorder(root1);
    printf("\n");

    int arr2[] = {10, 20, 30, 40};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    Node* root2 = buildBST(arr2, 0, n2 - 1);
    preorder(root2);
    printf("\n");

    return 0;
}