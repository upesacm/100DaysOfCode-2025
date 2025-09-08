#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

void printInRange(struct Node* root, int L, int R) {
    if (root == NULL) return;

    if (root->data > L)
        printInRange(root->left, L, R);

    if (root->data >= L && root->data <= R)
        printf("%d ", root->data);

    if (root->data < R)
        printInRange(root->right, L, R);
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 18);

    int L = 7, R = 15;
    printf("Nodes in range [%d, %d]: ", L, R);
    printInRange(root, L, R);

    return 0;
}
