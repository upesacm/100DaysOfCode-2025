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
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

int rangeSumBST(struct Node* root, int L, int R) {
    if (root == NULL) return 0;

    if (root->data < L)
        return rangeSumBST(root->right, L, R);
    if (root->data > R)
        return rangeSumBST(root->left, L, R);

    return root->data + 
           rangeSumBST(root->left, L, R) + 
           rangeSumBST(root->right, L, R);
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
    printf("Range Sum [%d, %d] = %d\n", L, R, rangeSumBST(root, L, R));

    return 0;
}
