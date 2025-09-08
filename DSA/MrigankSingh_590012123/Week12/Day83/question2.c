#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* createTree() {
    int data;
    printf("Enter node value (-1 for null): ");
    scanf("%d", &data);
    if (data == -1) return NULL;
    
    struct Node* root = createNode(data);
    printf("Enter left subtree of %d (BST order)\n", data);
    root->left = createTree();
    printf("Enter right subtree of %d (BST order)\n", data);
    root->right = createTree();
    return root;
}

void serialize(struct Node* root, char* result, int* index) {
    if (root == NULL) return;
    
    *index += sprintf(result + *index, "%d,", root->data);
    serialize(root->left, result, index);
    serialize(root->right, result, index);
}

struct Node* deserializeUtil(char* str, int* index, int min, int max) {
    if (str[*index] == '\0') return NULL;
    
    int num = 0;
    int sign = 1;
    if (str[*index] == '-') {
        sign = -1;
        (*index)++;
    }
    
    while (str[*index] >= '0' && str[*index] <= '9') {
        num = num * 10 + (str[*index] - '0');
        (*index)++;
    }
    num *= sign;
    
    if (num < min || num > max) return NULL;
    
    struct Node* root = createNode(num);
    
    if (str[*index] == ',') (*index)++;
    
    root->left = deserializeUtil(str, index, min, num);
    root->right = deserializeUtil(str, index, num, max);
    
    return root;
}

struct Node* deserialize(char* str) {
    int index = 0;
    return deserializeUtil(str, &index, INT_MIN, INT_MAX);
}

void printInorder(struct Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    printf("Create BST (preorder, enter -1 for null nodes, maintain BST property):\n");
    struct Node* root = createTree();
    
    char result[1000] = "";
    int index = 0;
    serialize(root, result, &index);
    printf("Serialized: %s\n", result);
    
    struct Node* deserializedRoot = deserialize(result);
    printf("Deserialized Inorder: ");
    printInorder(deserializedRoot);
    printf("\n");
    
    return 0;
}
