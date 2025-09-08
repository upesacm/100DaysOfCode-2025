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

// Build balanced BST from sorted array
struct Node* build(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    struct Node* root = create(arr[mid]);

    root->left = build(arr, start, mid - 1);
    root->right = build(arr, mid + 1, end);

    return root;
}

// Preorder traversal to show structure
void preorder(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* root = build(arr, 0, n - 1);

    printf("Preorder of Balanced BST: ");
    preorder(root);  // Output: 4 2 1 3 6 5 7
    printf("\n");

    return 0;
}
