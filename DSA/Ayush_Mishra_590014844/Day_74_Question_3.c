#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void printPaths(struct Node* root, int path[], int pathLen) {
    if (root == NULL) return;

    path[pathLen] = root->data;
    pathLen++;

    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < pathLen; i++)
            printf("%d%s", path[i], (i == pathLen - 1) ? "\n" : "->");
    } else {
        printPaths(root->left, path, pathLen);
        printPaths(root->right, path, pathLen);
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(5);

    int path[100];
    printf("All root-to-leaf paths:\n");
    printPaths(root, path, 0);

    return 0;
}
