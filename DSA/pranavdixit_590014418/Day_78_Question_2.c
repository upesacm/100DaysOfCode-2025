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

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);

    insert(root, 4);

    printf("Inorder after insertion: ");
    inorder(root);
    printf("\n");

    struct Node* root2 = NULL;
    root2 = insert(root2, 10);
    insert(root2, 20);

    printf("Inorder of second tree: ");
    inorder(root2);
    printf("\n");

    return 0;
}
