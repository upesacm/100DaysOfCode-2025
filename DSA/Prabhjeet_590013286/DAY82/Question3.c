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

// Reverse inorder traversal to convert to greater tree
void convert(struct Node* root, int* sum)
{
    if (root == NULL)
    {
        return;
    }

    convert(root->right, sum);

    *sum += root->data;
    root->data = *sum;

    convert(root->left, sum);
}

// Inorder traversal to show updated values
void inorder(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    struct Node* root = create(5);
    root->left = create(2);
    root->right = create(13);

    int sum = 0;
    convert(root, &sum);

    printf("Inorder of Greater Tree: ");
    inorder(root);  // Output: 20 18 13
    printf("\n");

    return 0;
}
