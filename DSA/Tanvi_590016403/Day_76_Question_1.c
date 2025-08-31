#include <stdio.h>
#include <stdlib.h>

// ------------------ Node Structure ------------------
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// ------------------ Create New Node ------------------
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// ------------------ 1. Convert to Sum Tree ------------------
int toSumTree(struct Node* root) {
    if (root == NULL)
        return 0;

    // Store old value
    int old_val = root->data;

    // Recursively convert left and right subtrees
    root->data = toSumTree(root->left) + toSumTree(root->right);

    // Return sum of new value + old value to parent
    return root->data + old_val;
}

// Inorder traversal (for checking Sum Tree)
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// ------------------ 2. Print Ancestors ------------------
int printAncestors(struct Node* root, int target) {
    if (root == NULL) return 0;

    if (root->data == target) return 1;

    if (printAncestors(root->left, target) || printAncestors(root->right, target)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

// ------------------ 3. Count Nodes at Given Level ------------------
int countLevelNodes(struct Node* root, int level) {
    if (root == NULL) return 0;
    if (level == 0) return 1;
    return countLevelNodes(root->left, level - 1) + countLevelNodes(root->right, level - 1);
}

// ------------------ Main ------------------
int main() {
    /* Example Tree
             10
            /  \
          -2    6
          / \  / \
         8 -4 7  5
    */
    struct Node* root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    // 1. Convert to Sum Tree
    toSumTree(root);
    printf("Inorder traversal of Sum Tree: ");
    inorder(root);
    printf("\n");

    // 2. Print Ancestors of node
    int target = 7;
    printf("Ancestors of %d: ", target);
    printAncestors(root, target);
    printf("\n");

    // 3. Count Nodes at Given Level
    int level = 2;
    printf("Nodes at level %d = %d\n", level, countLevelNodes(root, level));

    return 0;
}
