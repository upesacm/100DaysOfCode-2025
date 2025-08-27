#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

/* ================= Problem 1 =================
   Mirror of Binary Tree (recursive subtree swap) */
void mirrorTree(struct Node* root) {
    if (root == NULL) return;

    // Swap left and right children
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror left and right subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

/* ================= Problem 2 =================
   Check if Two Trees are Identical */
int areIdentical(struct Node* root1, struct Node* root2) {
    // Both empty -> identical
    if (root1 == NULL && root2 == NULL) return 1;

    // Both non-empty -> check recursively
    if (root1 != NULL && root2 != NULL) {
        return (root1->data == root2->data &&
                areIdentical(root1->left, root2->left) &&
                areIdentical(root1->right, root2->right));
    }

    // One empty, one not -> not identical
    return 0;
}

/* ================= Problem 3 =================
   Count Nodes in Binary Tree */
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

/* Utility function: Inorder Traversal (for display) */
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* ================= Main Function ================= */
int main() {
    // Create a sample tree
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    printf("Inorder of Original Tree: ");
    inorder(root1);
    printf("\n");

    // Problem 1: Mirror
    mirrorTree(root1);
    printf("Inorder of Mirrored Tree: ");
    inorder(root1);
    printf("\n");

    // Problem 2: Check Identical
    struct Node* root2 = newNode(1);
    root2->left = newNode(3);
    root2->right = newNode(2);
    root2->right->left = newNode(5);
    root2->right->right = newNode(4);

    if (areIdentical(root1, root2))
        printf("Trees are Identical\n");
    else
        printf("Trees are Not Identical\n");

    // Problem 3: Count Nodes
    printf("Number of nodes in Tree1: %d\n", countNodes(root1));
    printf("Number of nodes in Tree2: %d\n", countNodes(root2));

    return 0;
}
