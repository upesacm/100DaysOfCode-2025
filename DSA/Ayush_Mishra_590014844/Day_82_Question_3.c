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

void convertToGreaterTree(Node* root, int* sum) {
    if (!root) return;
    convertToGreaterTree(root->right, sum);
    *sum += root->data;
    root->data = *sum;
    convertToGreaterTree(root->left, sum);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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
    int sum = 0;
    convertToGreaterTree(root, &sum);
    printf("Inorder traversal of Greater Tree:\n");
    inorder(root);
    return 0;
}
