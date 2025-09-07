#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* createTree() {
    int data;
    printf("Enter node value (-1 for null): ");
    scanf("%d", &data);
    if (data == -1) return NULL;
    
    struct Node* root = createNode(data);
    printf("Enter left subtree of %d (BST order)\n", data);
    root->left = createTree();
    printf("Enter right subtree of %d (BST order)\n", data);
    root->right = createTree();
    return root;
}

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    
    if (root->data > n1 && root->data > n2) {
        return findLCA(root->left, n1, n2);
    }
    else if (root->data < n1 && root->data < n2) {
        return findLCA(root->right, n1, n2);
    }
    
    return root;
}

int main() {
    printf("Create BST (preorder, enter -1 for null nodes, maintain BST property):\n");
    struct Node* root = createTree();
    int n1, n2;
    printf("Enter two node values to find LCA: ");
    scanf("%d %d", &n1, &n2);
    
    struct Node* lca = findLCA(root, n1, n2);
    if (lca != NULL) {
        printf("LCA of %d and %d is %d\n", n1, n2, lca->data);
    } else {
        printf("LCA not found\n");
    }
    return 0;
}
