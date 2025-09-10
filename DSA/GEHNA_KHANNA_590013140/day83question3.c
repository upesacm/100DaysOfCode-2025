#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (!root) return newNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void inorder(struct TreeNode* root, int arr[], int* idx) {
    if (!root) return;
    inorder(root->left, arr, idx);
    arr[(*idx)++] = root->val;
    inorder(root->right, arr, idx);
}

bool findTarget(struct TreeNode* root, int target) {
    int arr[1000], n = 0;
    inorder(root, arr, &n);
    int i = 0, j = n - 1;
    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == target) return true;
        else if (sum < target) i++;
        else j--;
    }
    return false;
}

int main() {
    int n, val, target; scanf("%d", &n);
    struct TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    scanf("%d", &target);
    if (findTarget(root, target)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
