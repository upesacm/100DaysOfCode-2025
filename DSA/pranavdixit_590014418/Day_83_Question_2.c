#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return newNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

void serializeHelper(struct Node* root, char* buffer) {
    if (root == NULL) return;
    char num[20];
    sprintf(num, "%d,", root->data);
    strcat(buffer, num);
    serializeHelper(root->left, buffer);
    serializeHelper(root->right, buffer);
}

char* serialize(struct Node* root) {
    char* buffer = (char*)malloc(1000);
    buffer[0] = '\0';
    serializeHelper(root, buffer);
    if (strlen(buffer) > 0) buffer[strlen(buffer) - 1] = '\0';
    return buffer;
}

struct Node* buildBSTFromPreorder(int* preorder, int* index, int min, int max, int n) {
    if (*index >= n) return NULL;

    int val = preorder[*index];
    if (val < min || val > max) return NULL;

    (*index)++;
    struct Node* root = newNode(val);
    root->left = buildBSTFromPreorder(preorder, index, min, val, n);
    root->right = buildBSTFromPreorder(preorder, index, val, max, n);

    return root;
}

struct Node* deserialize(char* data) {
    if (strlen(data) == 0) return NULL;

    int preorder[100], n = 0;
    char* token = strtok(data, ",");
    while (token) {
        preorder[n++] = atoi(token);
        token = strtok(NULL, ",");
    }

    int index = 0;
    return buildBSTFromPreorder(preorder, &index, -100000, 100000, n);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 2);
    insert(root, 1);
    insert(root, 3);

    char* s = serialize(root);
    printf("Serialized: %s\n", s);

    root = deserialize(s);
    printf("Deserialized Inorder: ");
    inorder(root);
    printf("\n");

    return 0;
}
