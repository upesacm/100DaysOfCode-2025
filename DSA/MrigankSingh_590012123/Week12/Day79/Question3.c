#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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
    printf("Enter left subtree of %d\n", data);
    root->left = createTree();
    printf("Enter right subtree of %d\n", data);
    root->right = createTree();
    return root;
}

bool isValidBSTUtil(struct Node* root, long min, long max) {
    if (root == NULL) return true;
    
    if (root->data <= min || root->data >= max) return false;
    
    return isValidBSTUtil(root->left, min, root->data) &&
           isValidBSTUtil(root->right, root->data, max);
}

bool isValidBST(struct Node* root) {
    return isValidBSTUtil(root, LONG_MIN, LONG_MAX);
}

int main() {
    printf("Create binary tree (preorder, enter -1 for null nodes):\n");
    struct Node* root = createTree();
    printf("%s\n", isValidBST(root) ? "Yes" : "No");
    return 0;
}
