#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void serialize_helper(TreeNode* root, char* str, int* pos) {
    if (root == NULL) return;
    *pos += sprintf(str + *pos, "%d,", root->val);
    serialize_helper(root->left, str, pos);
    serialize_helper(root->right, str, pos);
}

char* serialize(TreeNode* root) {
    char* str = (char*)malloc(1000 * sizeof(char));
    str[0] = '\0';
    int pos = 0;
    serialize_helper(root, str, &pos);
    if (pos > 0 && str[pos - 1] == ',') {
        str[pos - 1] = '\0';
    }
    return str;
}

TreeNode* deserialize_helper(int* arr, int* arr_idx, int min, int max) {
    if (*arr_idx >= 1000 || arr[*arr_idx] < min || arr[*arr_idx] > max) {
        return NULL;
    }
    
    TreeNode* root = createNode(arr[*arr_idx]);
    (*arr_idx)++;
    
    root->left = deserialize_helper(arr, arr_idx, min, root->val - 1);
    root->right = deserialize_helper(arr, arr_idx, root->val + 1, max);
    
    return root;
}

TreeNode* deserialize(char* data) {
    if (data == NULL || strlen(data) == 0) return NULL;
    
    int* arr = (int*)malloc(1000 * sizeof(int));
    int arr_idx = 0;
    char* token = strtok(data, ",");
    while (token != NULL) {
        arr[arr_idx++] = atoi(token);
        token = strtok(NULL, ",");
    }
    
    int current_idx = 0;
    return deserialize_helper(arr, &current_idx, -100000, 100000);
}

void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(2);
    root1->left = createNode(1);
    root1->right = createNode(3);
    char* serialized1 = serialize(root1);
    printf("Input Tree:\n  2\n / \\\n1   3\n");
    printf("Serialized: \"%s\"\n", serialized1);
    TreeNode* deserialized1 = deserialize(serialized1);
    printf("Deserialized Inorder: ");
    inorder(deserialized1);
    printf("\n");

    // Example 2
    TreeNode* root2 = createNode(5);
    root2->left = createNode(3);
    root2->right = createNode(7);
    char* serialized2 = serialize(root2);
    printf("\nInput Tree:\n  5\n / \\\n3   7\n");
    printf("Serialized: \"%s\"\n", serialized2);
    TreeNode* deserialized2 = deserialize(serialized2);
    printf("Deserialized Inorder: ");
    inorder(deserialized2);
    printf("\n");

    return 0;
}
