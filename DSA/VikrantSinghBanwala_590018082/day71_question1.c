#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = newNode(1);
    root->right = newNode(3);
    root->right->left = newNode(2);

    inorderTraversal(root);
    printf("\n");

    struct Node* root2 = newNode(4);
    root2->left = newNode(2);
    root2->right = newNode(5);

    inorderTraversal(root2);
    printf("\n");

    return 0;
}
