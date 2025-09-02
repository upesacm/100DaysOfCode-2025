#include <stdio.h>
#include <stdlib.h>

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

// Recursive function to count nodes at given level
int countNodesAtLevel(struct Node* root, int level) {
    if (root == NULL) return 0;

    if (level == 1) return 1;  // Current node is at the target level

    // Recurse for children, decrement level
    return countNodesAtLevel(root->left, level - 1) +
           countNodesAtLevel(root->right, level - 1);
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

    int level = 2;
    printf("Nodes at Level %d: %d", level, countNodesAtLevel(root, level));

    return 0;
}

