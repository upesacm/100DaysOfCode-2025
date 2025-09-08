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

bool findTargetUtil(struct Node* root, int target, struct Node* current, int currVal) {
    if (root == NULL) return false;
    
    int complement = target - currVal;
    if (complement != currVal && complement == root->data) return true;
    
    if (complement < root->data) {
        return findTargetUtil(root->left, target, current, currVal);
    } else {
        return findTargetUtil(root->right, target, current, currVal);
    }
}

bool findTarget(struct Node* root, int target) {
    if (root == NULL) return false;
    
    if (findTargetUtil(root, target, root, root->data)) return true;
    
    return findTarget(root->left, target) || findTarget(root->right, target);
}

int main() {
    printf("Create BST (preorder, enter -1 for null nodes, maintain BST property):\n");
    struct Node* root = createTree();
    int target;
    printf("Enter target sum: ");
    scanf("%d", &target);
    
    printf("%s\n", findTarget(root, target) ? "Yes" : "No");
    return 0;
}
