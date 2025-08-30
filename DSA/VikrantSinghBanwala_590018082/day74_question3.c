#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void printPathsRecur(Node* root, int path[], int pathLen) {
    if (!root) return;
    path[pathLen] = root->data;
    pathLen++;
    if (!root->left && !root->right) {
        for (int i = 0; i < pathLen; i++) {
            if (i > 0) printf("->");
            printf("%d", path[i]);
        }
        printf("\n");
    } else {
        printPathsRecur(root->left, path, pathLen);
        printPathsRecur(root->right, path, pathLen);
    }
}

void printAllRootToLeafPaths(Node* root) {
    int path[1000];
    printPathsRecur(root, path, 0);
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);

    printAllRootToLeafPaths(root);
    return 0;
}