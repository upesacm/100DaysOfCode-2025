#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

int searchBST(Node* root, int key) {
    while (root != NULL) {
        if (key == root->data) return 1;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return 0;
}

int main() {
    Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    int key = 4;
    if (searchBST(root, key)) printf("Yes\n");
    else printf("No\n");

    key = 10;
    if (searchBST(root, key)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
