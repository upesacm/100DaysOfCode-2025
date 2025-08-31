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


int max(int a, int b) {
    return (a > b) ? a : b;
}


int height(struct Node* root, int* diameter) {
    if (root == NULL) return 0;

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

  
    if (lh + rh > *diameter)
        *diameter = lh + rh;

    return 1 + max(lh, rh);
}


int diameter(struct Node* root) {
    int dia = 0;
    height(root, &dia);
    return dia;
}


int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Diameter of tree: %d\n", diameter(root));
    return 0;
}

