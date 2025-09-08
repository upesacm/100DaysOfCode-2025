#include <stdio.h>
#include <stdlib.h>

// BST Node structure
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* create(int val)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Helper to check balance and compute height
int check(struct Node* root, int* isBalanced)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = check(root->left, isBalanced);
    int rh = check(root->right, isBalanced);

    if (abs(lh - rh) > 1)
    {
        *isBalanced = 0;
    }

    return 1 + (lh > rh ? lh : rh);
}

int main()
{
    struct Node* root = create(4);
    root->left = create(2);
    root->right = create(6);
    root->left->left = create(1);
    root->left->right = create(3);
    root->right->left = create(5);
    root->right->right = create(7);

    int isBalanced = 1;
    check(root, &isBalanced);

    printf("Is BST Balanced? %s\n", isBalanced ? "Yes" : "No");  // Output: Yes

    return 0;
}
