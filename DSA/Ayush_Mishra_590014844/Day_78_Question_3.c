#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int val) {
    if (!root) return createNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int findMin(struct Node* root) {
    while (root && root->left) root = root->left;
    return root ? root->data : -1;
}

int findMax(struct Node* root) {
    while (root && root->right) root = root->right;
    return root ? root->data : -1;
}

int main() {
    int n, val;
    struct Node* root = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d node values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Min = %d, Max = %d\n", findMin(root), findMax(root));
    return 0;
}
