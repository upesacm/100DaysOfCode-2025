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

void printArray(int path[], int pathLen) {
    for (int i = 0; i < pathLen; i++) {
        printf("%d", path[i]);
        if (i != pathLen - 1) printf("->");
    }
    printf("\n");
}

void printPathsRecur(struct Node* node, int path[], int pathLen) {
    if (node == NULL) return;

    path[pathLen] = node->data;
    pathLen++;

    if (node->left == NULL && node->right == NULL) {
        printArray(path, pathLen);
    } else {
        printPathsRecur(node->left, path, pathLen);
        printPathsRecur(node->right, path, pathLen);
    }
}

void printPaths(struct Node* root) {
    int path[1000];
    printPathsRecur(root, path, 0);
}

// Example usage
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);

    printPaths(root);
    // Output:
    // 1->2->5
    // 1->3
    return 0;
}
