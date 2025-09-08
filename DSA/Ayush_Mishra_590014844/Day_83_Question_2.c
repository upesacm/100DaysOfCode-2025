#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int key) {
    if (!root) return newNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

void serialize(Node* root, char* buffer) {
    if (!root) return;
    char temp[10];
    sprintf(temp, "%d,", root->data);
    strcat(buffer, temp);
    serialize(root->left, buffer);
    serialize(root->right, buffer);
}

Node* buildTree(int* preorder, int* index, int min, int max, int size) {
    if (*index >= size) return NULL;
    int val = preorder[*index];
    if (val < min || val > max) return NULL;

    (*index)++;
    Node* root = newNode(val);
    root->left = buildTree(preorder, index, min, val, size);
    root->right = buildTree(preorder, index, val, max, size);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}

int main() {
    int n, val;
    Node* root = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    char buffer[1000] = "";
    serialize(root, buffer);
    buffer[strlen(buffer) - 1] = '\0';
    printf("Serialized: \"%s\"\n", buffer);

    int preorder[100], idx = 0;
    char* token = strtok(buffer, ",");
    while (token) {
        preorder[idx++] = atoi(token);
        token = strtok(NULL, ",");
    }

    int index = 0;
    Node* newRoot = buildTree(preorder, &index, -10000, 10000, idx);
    printf("Deserialized Inorder:\n");
    inorder(newRoot);
    printf("\n");
    return 0;
}
