#include <stdio.h>
#include <stdlib.h>

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
    printf("Enter left subtree of %d\n", data);
    root->left = createTree();
    printf("Enter right subtree of %d\n", data);
    root->right = createTree();
    return root;
}

int countNodesAtLevel(struct Node* root, int level) {
    if (root == NULL) return 0;
    if (level == 0) return 1;
    return countNodesAtLevel(root->left, level-1) + countNodesAtLevel(root->right, level-1);
}

int main() {
    printf("Create binary tree (preorder, enter -1 for null nodes):\n");
    struct Node* root = createTree();
    int level;
    printf("Enter target level (0-based): ");
    scanf("%d", &level);
    
    int count = countNodesAtLevel(root, level);
    printf("Number of nodes at level %d: %d\n", level, count);
    return 0;
}
