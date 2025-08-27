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
    node->left = node->right = NULL;
    return node;
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    // Example 1
    struct Node* root1 = newNode(1);
    root1->right = newNode(3);
    root1->right->left = newNode(2);
    printf("Inorder traversal: ");
    inorder(root1);  // 1 3 2
    printf("\n");

    // Example 2
    struct Node* root2 = newNode(4);
    root2->left = newNode(2);
    root2->right = newNode(5);
    printf("Inorder traversal: ");
    inorder(root2);  // 2 4 5
    printf("\n");

    return 0;
}
