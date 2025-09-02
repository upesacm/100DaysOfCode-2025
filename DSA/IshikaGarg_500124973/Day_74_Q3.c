#include <stdio.h>
#include <stdlib.h>

// Define a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Utility function to print path
void printPath(int path[], int pathLen) {
    for (int i = 0; i < pathLen; i++) {
        printf("%d", path[i]);
        if (i < pathLen - 1)
            printf("->");
    }
    printf("\n");
}

// Recursive function to print all root-to-leaf paths
void printPathsRec(struct Node* root, int path[], int pathLen) {
    if (root == NULL)
        return;

    // Add current node to path
    path[pathLen] = root->data;
    pathLen++;

    // If leaf node → print path
    if (root->left == NULL && root->right == NULL) {
        printPath(path, pathLen);
    } else {
        // Recur for left and right
        printPathsRec(root->left, path, pathLen);
        printPathsRec(root->right, path, pathLen);
    }
}

// Wrapper function
void printPaths(struct Node* root) {
    int path[1000]; // large enough for tree depth
    printPathsRec(root, path, 0);
}

// Driver code
int main() {
    /* Example tree:
            1
           / \
          2   3
           \
            5
       Output:
       1->2->5
       1->3
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);

    printf("All Root-to-Leaf Paths:\n");
    printPaths(root);

    return 0;
}

