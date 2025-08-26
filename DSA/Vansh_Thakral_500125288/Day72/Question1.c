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


void mirror(struct Node* root) {
    if (root == NULL) return;

    
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    printf("Inorder before mirror: ");
    inorder(root);
    printf("\n");

    mirror(root);

    printf("Inorder after mirror: ");
    inorder(root); 
    printf("\n");

    return 0;
}

