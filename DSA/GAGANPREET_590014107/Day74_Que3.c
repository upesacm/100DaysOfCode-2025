#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
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
        if (i < pathLen - 1) printf("->");
    }
    printf("\n");
}

void printPathsRec(struct Node* root, int path[], int pathLen) {
    if (root == NULL) return;
    path[pathLen] = root->data;
    pathLen++;
    if (root->left == NULL && root->right == NULL) {
        printArray(path, pathLen);
    } else {
        printPathsRec(root->left, path, pathLen);
        printPathsRec(root->right, path, pathLen);
    }
}

void printPaths(struct Node* root) {
    int path[1000];
    printPathsRec(root, path, 0);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);

    printf("All root-to-leaf paths:\n");
    printPaths(root);
    return 0;
}
