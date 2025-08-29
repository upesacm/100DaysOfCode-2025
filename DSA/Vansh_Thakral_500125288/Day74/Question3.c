#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

void printPaths(struct Node* root, int path[], int pathLen) {
    if (root == NULL) return;

    
    path[pathLen] = root->value;
    pathLen++;

    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < pathLen; i++) {
            printf("%d", path[i]);
            if (i < pathLen - 1) printf("->");
        }
        printf("\n");
    } else {
    
        printPaths(root->left, path, pathLen);
        printPaths(root->right, path, pathLen);
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);

    int path[100]; 
    printf("Root-to-leaf paths:\n");
    printPaths(root, path, 0);



    return 0;
}

