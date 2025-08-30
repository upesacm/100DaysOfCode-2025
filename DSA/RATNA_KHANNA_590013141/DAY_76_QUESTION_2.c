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
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool printAncestors(struct Node* root, int target) {
    if (root == NULL)
        return false;

    // If target node is found, return true
    if (root->data == target)
        return true;

    // Check in left or right subtree
    if (printAncestors(root->left, target) || printAncestors(root->right, target)) {
        printf("%d ", root->data);  // Print the current node
        return true;
    }

    return false;
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    int target;
    printf("Enter the target node value: ");
    scanf("%d", &target);

    printf("Ancestors of node %d: ", target);
    if (!printAncestors(root, target)) {
        printf("Node not found in the tree.\n");
    }
    printf("\n");

    return 0;
}
