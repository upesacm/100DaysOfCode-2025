#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to print ancestors
bool printAncestors(struct Node* root, int target) {
    if (root == NULL) return false;

    // If target node found
    if (root->data == target)
        return true;

    // If target is present in either subtree
    if (printAncestors(root->left, target) || printAncestors(root->right, target)) {
        printf("%d ", root->data);
        return true;
    }

    return false;
}

int main() {
    /* Example Tree
             1
            / \
           2   3
          /
         4
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    int target = 4;
    printf("Ancestors of %d: ", target);
    printAncestors(root, target);

    return 0;
}

