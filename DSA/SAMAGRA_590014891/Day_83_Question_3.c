#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void inorder(Node* root, int* arr, int* n) {
    if(!root) return;
    inorder(root->left, arr, n);
    arr[(*n)++] = root->val;
    inorder(root->right, arr, n);
}

int twoSumBST(Node* root, int target) {
    int arr[1000], n=0;
    inorder(root, arr, &n);
    int i=0, j=n-1;
    while(i<j) {
        int sum = arr[i]+arr[j];
        if(sum==target) return 1;
        else if(sum<target) i++;
        else j--;
    }
    return 0;
}

int main() {
    Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->right = newNode(7);

    printf(twoSumBST(root,9) ? "Yes\n" : "No\n");
    printf(twoSumBST(root,28) ? "Yes\n" : "No\n");
    return 0;
}
