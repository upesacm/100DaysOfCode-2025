#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


int toSumTree(struct Node* root) {
    if (root == NULL)
        return 0;

    
    int leftSum = toSumTree(root->left);
    int rightSum = toSumTree(root->right);

    
    int oldValue = root->data;

   
    root->data = leftSum + rightSum;

    return root->data + oldValue;
}


void printInorder(struct Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}


int main() {
    struct Node* root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    toSumTree(root);

    printf("Inorder traversal of Sum Tree: ");
    printInorder(root);
    printf("\n");
    return 0;
}

