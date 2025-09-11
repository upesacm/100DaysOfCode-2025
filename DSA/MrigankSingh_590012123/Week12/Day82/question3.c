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
    printf("Enter left subtree of %d (BST order)\n", data);
    root->left = createTree();
    printf("Enter right subtree of %d (BST order)\n", data);
    root->right = createTree();
    return root;
}

void convertToGreaterTreeUtil(struct Node* root, int* sum) {
    if (root == NULL) return;
    
    convertToGreaterTreeUtil(root->right, sum);
    
    *sum += root->data;
    root->data = *sum;
    
    convertToGreaterTreeUtil(root->left, sum);
}

void convertToGreaterTree(struct Node* root) {
    int sum = 0;
    convertToGreaterTreeUtil(root, &sum);
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
    convertToGreaterTree(root);
    printf("Inorder traversal of Greater Tree: ");
    printInorder(root);
    printf("\n");
    return 0;
}
