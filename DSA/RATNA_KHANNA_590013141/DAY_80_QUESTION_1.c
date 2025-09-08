#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (n1 < root->data && n2 < root->data) 
        return findLCA(root->left, n1, n2);
    if (n1 > root->data && n2 > root->data) 
        return findLCA(root->right, n1, n2);
    return root;
}

int main() {
    int n, value, i, node1, node2;
    struct Node* root = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter tree values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("Enter two nodes to find LCA: ");
    scanf("%d %d", &node1, &node2);
    struct Node* lca = findLCA(root, node1, node2);
    if (lca != NULL) 
        printf("Lowest Common Ancestor: %d", lca->data);
    else 
        printf("Nodes not found in the tree");
    return 0;
}
