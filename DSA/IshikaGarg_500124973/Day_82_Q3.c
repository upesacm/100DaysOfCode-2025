#include <stdio.h>
#include <stdlib.h>

// Define a node of the BST
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to convert BST to Greater Tree
void convertBST(struct Node* root, int* sum) {
    if (root == NULL)
        return;

    // Traverse right subtree first (greater values)
    convertBST(root->right, sum);

    // Update current node
    *sum += root->key;
    root->key = *sum;

    // Traverse left subtree
    convertBST(root->left, sum);
}

// Wrapper function
void bstToGreaterTree(struct Node* root) {
    int sum = 0;
    convertBST(root, &sum);
}

// Inorder traversal to print tree values
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

// -------------------- TESTING --------------------
int main() {
    // Example 1:
    // Input Tree:
    //     5
    //    / \
    //   2   13
    struct Node* root1 = newNode(5);
    root1->left = newNode(2);
    root1->right = newNode(13);

    bstToGreaterTree(root1);
    printf("Inorder of Greater Tree (Example 1): ");
    inorder(root1);  // Expected: 20 18 13
    printf("\n");

    // Example 2:
    // Input Tree:
    //       2
    //      / \
    //     0   3
    //    / \
    //  -4   1
    struct Node* root2 = newNode(2);
    root2->left = newNode(0);
    root2->right = newNode(3);
    root2->left->left = newNode(-4);
    root2->left->right = newNode(1);

    bstToGreaterTree(root2);
    printf("Inorder of Greater Tree (Example 2): ");
    inorder(root2);  // Expected: 2 6 5 3 3
    printf("\n");

    return 0;
}

