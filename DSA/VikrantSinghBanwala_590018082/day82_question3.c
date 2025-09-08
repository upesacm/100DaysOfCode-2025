#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

void convertBSTUtil(Node* root, int* sum) {
    if (!root) return;
    convertBSTUtil(root->right, sum);
    *sum += root->val;
    root->val = *sum;
    convertBSTUtil(root->left, sum);
}

void convertBST(Node* root) {
    int sum = 0;
    convertBSTUtil(root, &sum);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    Node* root1 = newNode(5);
    root1->left = newNode(2);
    root1->right = newNode(13);
    convertBST(root1);
    inorder(root1);
    printf("\n");

    Node* root2 = newNode(2);
    root2->left = newNode(0);
    root2->right = newNode(3);
    root2->left->left = newNode(-4);
    root2->left->right = newNode(1);
    convertBST(root2);
    inorder(root2);
    printf("\n");

    return 0;
}