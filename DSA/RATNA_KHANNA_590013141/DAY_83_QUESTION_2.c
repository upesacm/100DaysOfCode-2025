#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

void serializeHelper(struct Node* root, char* result) {
    if (!root) return;
    char buffer[20];
    sprintf(buffer, "%d,", root->data);
    strcat(result, buffer);
    serializeHelper(root->left, result);
    serializeHelper(root->right, result);
}

char* serialize(struct Node* root) {
    char* result = (char*)malloc(1000 * sizeof(char));
    result[0] = '\0';
    serializeHelper(root, result);
    int len = strlen(result);
    if (len > 0 && result[len-1] == ',') result[len-1] = '\0';
    return result;
}

struct Node* buildTree(int* preorder, int* index, int n, int min, int max) {
    if (*index >= n) return NULL;
    int val = preorder[*index];
    if (val < min || val > max) return NULL;
    (*index)++;
    struct Node* root = newNode(val);
    root->left = buildTree(preorder, index, n, min, val - 1);
    root->right = buildTree(preorder, index, n, val + 1, max);
    return root;
}

struct Node* deserialize(char* data) {
    if (strlen(data) == 0) return NULL;
    int preorder[1000], n = 0;
    char* token = strtok(data, ",");
    while (token) {
        preorder[n++] = atoi(token);
        token = strtok(NULL, ",");
    }
    int index = 0;
    return buildTree(preorder, &index, n, INT_MIN, INT_MAX);
}

void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    char* serialized = serialize(root);
    printf("Serialized: %s\n", serialized);

    struct Node* newRoot = deserialize(serialized);
    printf("Deserialized Inorder: ");
    inorder(newRoot);
    printf("\n");
    return 0;
}
