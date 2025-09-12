#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}
struct Node* insert(struct Node* root, int value) 
{
    if (root == NULL) return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}
void serialize(struct Node* root, char* str) 
{
    if (root == NULL) return;
    char buffer[20];
    sprintf(buffer, "%d ", root->data);
    strcat(str, buffer);
    serialize(root->left, str);
    serialize(root->right, str);
}
struct Node* deserializeHelper(int* preorder, int* index, int size, int min, int max) 
{
    if (*index >= size) return NULL;
    int val = preorder[*index];
    if (val < min || val > max) return NULL;
    (*index)++;
    struct Node* root = createNode(val);
    root->left = deserializeHelper(preorder, index, size, min, val - 1);
    root->right = deserializeHelper(preorder, index, size, val + 1, max);
    return root;
}
struct Node* deserialize(char* str) 
{
    int preorder[1000], n = 0;
    char* token = strtok(str, " ");
    while (token != NULL) 
    {
        preorder[n++] = atoi(token);
        token = strtok(NULL, " ");
    }
    int index = 0;
    return deserializeHelper(preorder, &index, n, -2147483648, 2147483647);
}
void inorder(struct Node* root) 
{
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main() 
{
    struct Node* root = NULL;
    int n, val;
    char str[1000] = "";
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    char serialized[1000] = "";
    serialize(root, serialized);
    printf("Serialized BST: %s\n", serialized);
    struct Node* newRoot = deserialize(serialized);
    printf("Inorder traversal of deserialized BST: ");
    inorder(newRoot);
    printf("\n");
    return 0;
}
