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


void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}


int main() {
    struct Node* root = newNode(1);
    root->right = newNode(3);
    root->right->left = newNode(2);

    printf("Inorder Traversal: ");
    inorderTraversal(root);  
    return 0;
}

