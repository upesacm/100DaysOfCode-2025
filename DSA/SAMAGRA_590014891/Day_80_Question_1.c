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
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (!root) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

struct Node* LCA(struct Node* root, int n1, int n2) {
    while (root) {
        if (n1 < root->data && n2 < root->data)
            root = root->left;
        else if (n1 > root->data && n2 > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main() {
    struct Node* root = NULL;
    int nodes[] = {6, 2, 8, 0, 4, 7, 9};
    for (int i = 0; i < 7; i++) root = insert(root, nodes[i]);

    int n1 = 2, n2 = 4;
    struct Node* ancestor = LCA(root, n1, n2);
    if (ancestor) printf("%d\n", ancestor->data);
    return 0;
}
