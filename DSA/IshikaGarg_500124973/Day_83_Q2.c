#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Serialize (preorder)
void serializeHelper(struct Node* root, char* str) {
    if (!root) return;
    char buffer[20];
    sprintf(buffer, "%d,", root->val);
    strcat(str, buffer);
    serializeHelper(root->left, str);
    serializeHelper(root->right, str);
}

char* serialize(struct Node* root) {
    char* str = (char*)malloc(1000);
    str[0] = '\0';
    serializeHelper(root, str);
    if (strlen(str) > 0) str[strlen(str) - 1] = '\0'; // remove last comma
    return str;
}

// Deserialize using bounds
struct Node* deserializeHelper(int* preorder, int* index, int size, int min, int max) {
    if (*index >= size) return NULL;

    int val = preorder[*index];
    if (val < min || val > max) return NULL;

    (*index)++;
    struct Node* root = newNode(val);
    root->left = deserializeHelper(preorder, index, size, min, val);
    root->right = deserializeHelper(preorder, index, size, val, max);
    return root;
}

struct Node* deserialize(char* data) {
    if (!data || strlen(data) == 0) return NULL;

    int preorder[100], size = 0;
    char* token = strtok(data, ",");
    while (token) {
        preorder[size++] = atoi(token);
        token = strtok(NULL, ",");
    }

    int index = 0;
    return deserializeHelper(preorder, &index, size, INT_MIN, INT_MAX);
}

// Inorder traversal to check correctness
void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    struct Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);

    char* s = serialize(root);
    printf("Serialized: %s\n", s);

    struct Node* newRoot = deserialize(s);
    printf("Deserialized Inorder: ");
    inorder(newRoot); // Expected: 3 5 7
    printf("\n");
    free(s);
    return 0;
}

