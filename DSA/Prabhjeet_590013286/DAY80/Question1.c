#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Find LCA using BST property
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);
    else if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);
    else
        return root;
}

int main() {
  
    struct Node* root = createNode(6);
    root->left = createNode(2);
    root->right = createNode(8);
    root->left->left = createNode(0);
    root->left->right = createNode(4);
    root->right->left = createNode(7);
    root->right->right = createNode(9);

    int n1 = 2, n2 = 4;
    struct Node* lca = findLCA(root, n1, n2);
    printf("LCA of %d and %d is: %d\n", n1, n2, lca->data);  // Output: 2

    return 0;
}
