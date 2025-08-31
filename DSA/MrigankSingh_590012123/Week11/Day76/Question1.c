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

void printInorder(struct Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int toSumTree(struct Node* root) {
    if (root == NULL) return 0;
    
    int oldValue = root->data;
    
    int leftSum = toSumTree(root->left);
    int rightSum = toSumTree(root->right);
    
    root->data = leftSum + rightSum;
    
    return oldValue + root->data;
}

int main() {
    printf("Create binary tree (preorder, enter -1 for null nodes):\n");
    struct Node* root = createTree();
    printf("Original tree (inorder): ");
    printInorder(root);
    printf("\n");
    
    toSumTree(root);
    
    printf("Sum tree (inorder): ");
    printInorder(root);
    printf("\n");
    return 0;
}
