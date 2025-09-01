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
    printf("Enter left subtree of %d\n", data);
    root->left = createTree();
    printf("Enter right subtree of %d\n", data);
    root->right = createTree();
    return root;
}

bool printAncestors(struct Node* root, int target) {
    if (root == NULL) return false;
    
    if (root->data == target) return true;
    
    if (printAncestors(root->left, target) || printAncestors(root->right, target)) {
        printf("%d ", root->data);
        return true;
    }
    
    return false;
}

int main() {
    printf("Create binary tree (preorder, enter -1 for null nodes):\n");
    struct Node* root = createTree();
    int target;
    printf("Enter target node value: ");
    scanf("%d", &target);
    
    printf("Ancestors of %d: ", target);
    if (!printAncestors(root, target)) {
        printf("Node not found\n");
    } else {
        printf("\n");
    }
    return 0;
}
