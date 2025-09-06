#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int key) {
    if (!root) return newNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

void inorder(Node* root, int* arr, int* idx) {
    if (!root) return;
    inorder(root->left, arr, idx);
    arr[(*idx)++] = root->data;
    inorder(root->right, arr, idx);
}

int twoSum(int* arr, int n, int target) {
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
    int n, val, target;
    Node* root = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter target sum: ");
    scanf("%d", &target);

    int arr[1000], idx = 0;
    inorder(root, arr, &idx);

    if (twoSum(arr, idx, target)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
