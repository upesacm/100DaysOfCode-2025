#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int val)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Serialize using preorder
void serialize(struct Node* root, char* result)
{
    if (root == NULL)
    {
        return;
    }

    char buffer[10];
    sprintf(buffer, "%d,", root->data);
    strcat(result, buffer);

    serialize(root->left, result);
    serialize(root->right, result);
}

// Deserialize using BST property
struct Node* deserializeHelper(int* arr, int* index, int min, int max, int size)
{
    if (*index >= size)
    {
        return NULL;
    }

    int val = arr[*index];
    if (val < min || val > max)
    {
        return NULL;
    }

    (*index)++;
    struct Node* root = create(val);
    root->left = deserializeHelper(arr, index, min, val, size);
    root->right = deserializeHelper(arr, index, val, max, size);

    return root;
}

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
    struct Node* root = create(2);
    root->left = create(1);
    root->right = create(3);

    char result[100] = "";
    serialize(root, result);
    printf("Serialized: %s\n", result);  // Output: 2,1,3,

    int arr[] = {2, 1, 3};
    int index = 0;
    struct Node* newRoot = deserializeHelper(arr, &index, -1000, 1000, 3);

    printf("Deserialized Inorder: ");
    inorder(newRoot);  // Output: 1 2 3
    printf("\n");

    return 0;
}
