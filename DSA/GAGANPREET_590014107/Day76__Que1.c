#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


int convertToSumTree(Node* root) {
    if (root == NULL)
        return 0;

    
    int leftSum = convertToSumTree(root->left);
    int rightSum = convertToSumTree(root->right);

    
    int oldValue = root->data;

    
    root->data = leftSum + rightSum;

    
    return root->data + oldValue;
}


void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


int main() {
    
        
          

    Node* root = createNode(10);
    root->left = createNode(-2);
    root->right = createNode(6);
    root->left->left = createNode(8);
    root->left->right = createNode(-4);
    root->right->left = createNode(7);
    root->right->right = createNode(5);

    printf("In-order before conversion: ");
    inorder(root);
    printf("\n");

    convertToSumTree(root);

    printf("In-order after conversion: ");
    inorder(root);
    printf("\n");

    
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
