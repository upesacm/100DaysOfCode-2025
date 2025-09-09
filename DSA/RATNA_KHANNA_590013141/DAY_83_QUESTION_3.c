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

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

void inorder(struct Node* root, int arr[], int* idx) {
    if (!root) return;
    inorder(root->left, arr, idx);
    arr[(*idx)++] = root->data;
    inorder(root->right, arr, idx);
}

int twoSumBST(struct Node* root, int target) {
    int arr[1000], n = 0;
    inorder(root, arr, &n);
    int l = 0, r = n - 1;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == target) return 1;
        else if (sum < target) l++;
        else r--;
    }
    return 0;
}

int main() {
    struct Node* root = NULL;
    int n, val, target;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter target sum: ");
    scanf("%d", &target);
    if (twoSumBST(root, target)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
