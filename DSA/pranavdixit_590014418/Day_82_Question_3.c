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

void convertToGreaterTree(struct Node* root, int* sum) {
    if (root == NULL) return;

    convertToGreaterTree(root->right, sum);

    *sum += root->data;
    root->data = *sum;

    convertToGreaterTree(root->left, sum);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 5);
    insert(root, 2);
    insert(root, 13);

    int sum = 0;
    convertToGreaterTree(root, &sum);

    printf("Inorder after conversion: ");
    inorder(root);
    printf("\n");

    return 0;
}
