#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ---------------- Binary Tree Node ----------------
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

// ---------------- 1. Print Nodes at K Distance ----------------
void printKDistance(struct Node* root, int k) {
    if (root == NULL) return;
    if (k == 0) {
        printf("%d ", root->data);
        return;
    }
    printKDistance(root->left, k - 1);
    printKDistance(root->right, k - 1);
}

// ---------------- 2. Check if Tree is Balanced ----------------
int height(struct Node* root, bool* balanced) {
    if (root == NULL) return 0;

    int lh = height(root->left, balanced);
    int rh = height(root->right, balanced);

    if (abs(lh - rh) > 1)
        *balanced = false;

    return 1 + (lh > rh ? lh : rh);
}

bool isBalanced(struct Node* root) {
    bool balanced = true;
    height(root, &balanced);
    return balanced;
}

// ---------------- 3. Print All Root to Leaf Paths ----------------
void printPathsUtil(struct Node* root, int path[], int pathLen) {
    if (root == NULL) return;

    path[pathLen] = root->data;
    pathLen++;

    // Leaf node → print path
    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < pathLen; i++) {
            printf("%d", path[i]);
            if (i < pathLen - 1) printf("->");
        }
        printf("\n");
    } else {
        // Recurse on left and right
        printPathsUtil(root->left, path, pathLen);
        printPathsUtil(root->right, path, pathLen);
    }
}

void printPaths(struct Node* root) {
    int path[1000];  // buffer for storing path
    printPathsUtil(root, path, 0);
}

// ---------------- Main ----------------
int main() {
    /*
          1
         / \
        2   3
       / \
      4   5
           \
            6
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(6);

    printf("1. Nodes at distance K=2:\n");
    printKDistance(root, 2);   // Expected: 4 5
    printf("\n\n");

    printf("2. Is tree balanced?\n");
    if (isBalanced(root))
        printf("Yes\n");
    else
        printf("No\n");
    printf("\n");

    printf("3. All Root to Leaf Paths:\n");
    printPaths(root);
    printf("\n");

    return 0;
}
