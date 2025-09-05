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

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return newNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

void inorder(struct Node* root, int arr[], int* n) {
    if (root == NULL) return;
    inorder(root->left, arr, n);
    arr[(*n)++] = root->data;
    inorder(root->right, arr, n);
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
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);

    int target = 9;
    if (twoSumBST(root, target))
        printf("Yes\n");
    else
        printf("No\n");

    target = 28;
    if (twoSumBST(root, target))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
