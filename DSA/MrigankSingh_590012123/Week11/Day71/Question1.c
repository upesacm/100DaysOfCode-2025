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
    printf("Enter node data (-1 for no node): ");
    scanf("%d", &data);
    
    if (data == -1) {
        return NULL;
    }
    
    struct Node* root = createNode(data);
    
    printf("Enter left child of %d\n", data);
    root->left = createTree();
    
    printf("Enter right child of %d\n", data);
    root->right = createTree();
    
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void freeTree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    printf("Enter tree nodes (-1 for no node):\n");
    struct Node* root = createTree();
    
    printf("\nInorder Traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    freeTree(root);
    return 0;
}
