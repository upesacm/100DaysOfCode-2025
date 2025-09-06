#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int val) {
    if (!root) return createNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int height(Node* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int isBalanced(Node* root) {
    if (!root) return 1;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1) return 0;
    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    int n, val;
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);
    Node* root = NULL;
    printf("Enter node values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    if (isBalanced(root)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
