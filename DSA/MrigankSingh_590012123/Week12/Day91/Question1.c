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

int rangeSumBST(struct Node* root, int L, int R) {
    if (root == NULL) return 0;
    
    if (root->data < L) {
        return rangeSumBST(root->right, L, R);
    }
    if (root->data > R) {
        return rangeSumBST(root->left, L, R);
    }
    
    return root->data + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
}

int main() {
    printf("Create BST (preorder, enter -1 for null nodes, maintain BST property):\n");
    struct Node* root = createTree();
    int L, R;
    printf("Enter range [L, R]: ");
    scanf("%d %d", &L, &R);
    
    int sum = rangeSumBST(root, L, R);
    printf("Sum of nodes in range [%d, %d]: %d\n", L, R, sum);
    return 0;
}
