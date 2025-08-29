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

void printPathsUtil(struct Node* root, int path[], int pathLen) {
    if (root == NULL) return;

    path[pathLen] = root->data;
    pathLen++;

    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < pathLen; i++) {
            printf("%d", path[i]);
            if (i != pathLen - 1) printf("->");
        }
        printf("\n");
    } else {
        printPathsUtil(root->left, path, pathLen);
        printPathsUtil(root->right, path, pathLen);
    }
}

void printPaths(struct Node* root) {
    int path[1000];
    printPathsUtil(root, path, 0);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);

    printf("Root to leaf paths:\n");
    printPaths(root);
    // 1->2->5
    // 1->3

    return 0;
}
