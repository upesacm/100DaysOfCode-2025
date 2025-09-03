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

struct Node* buildTree() {
    int val;
    if (scanf("%d", &val) != 1 || val == -1) return NULL;
    struct Node* root = newNode(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printPaths(struct Node* root, int path[], int pathLen) {
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
        printPaths(root->left, path, pathLen);
        printPaths(root->right, path, pathLen);
    }
}

int main() {
    struct Node* root = buildTree();
    int path[1000];
    printPaths(root, path, 0);
    return 0;
}
