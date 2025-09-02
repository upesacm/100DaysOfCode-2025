#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create() {
    int x;
    scanf("%d", &x);
    if (x == -1) {
        return NULL;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->left = create();
    newNode->right = create();
    return newNode;
}

void mirror(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = create();
    printf("Original inorder: ");
    inorder(root);
    printf("\n");
    mirror(root);
    printf("Mirrored inorder: ");
    inorder(root);
    printf("\n");
    return 0;
}
