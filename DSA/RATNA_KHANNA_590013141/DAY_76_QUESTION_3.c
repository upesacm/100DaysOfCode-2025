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

int countNodesAtLevel(struct Node* root, int level) {
    if (root == NULL) {
        return 0; // No node at this level
    }

    if (level == 0) {
        return 1; // Found a node at the target level
    }

    // Recursively count nodes at the given level in both subtrees
    return countNodesAtLevel(root->left, level - 1) + countNodesAtLevel(root->right, level - 1);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    int level;
    printf("Enter the level: ");
    scanf("%d", &level);

    int result = countNodesAtLevel(root, level);
    printf("Number of nodes at level %d: %d\n", level, result);

    return 0;
}

