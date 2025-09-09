#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int height(struct Node* root, bool* isBalanced) {
    if (root == NULL) return 0;
    
    int leftHeight = height(root->left, isBalanced);
    int rightHeight = height(root->right, isBalanced);
    
    if (abs(leftHeight - rightHeight) > 1) {
        *isBalanced = false;
    }
    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalanced(struct Node* root) {
    bool balanced = true;
    height(root, &balanced);
    return balanced;
}

int main() {
    printf("Create BST (preorder, enter -1 for null nodes, maintain BST property):\n");
    struct Node* root = createTree();
    printf("%s\n", isBalanced(root) ? "Yes" : "No");
    return 0;
}
