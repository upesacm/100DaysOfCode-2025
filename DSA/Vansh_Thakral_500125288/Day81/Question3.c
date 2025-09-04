#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else if (val > root->val) root->right = insert(root->right, val);
    return root;
}

void printRange(struct Node* root, int L, int R) {
    if (root == NULL) return;

    if (root->val > L) 
        printRange(root->left, L, R);

    if (root->val >= L && root->val <= R) 
        printf("%d ", root->val);

    if (root->val < R) 
        printRange(root->right, L, R);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 18);

    int L = 7, R = 15;
    printf("Nodes in Range [%d, %d]: ", L, R);
    printRange(root, L, R);
    printf("\n");

    return 0;
}
