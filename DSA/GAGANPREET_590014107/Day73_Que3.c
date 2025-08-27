#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


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


int findMax(Node* root) {
    if (root == NULL)
        return INT_MIN; 

    int leftMax = findMax(root->left);     
    int rightMax = findMax(root->right);   

    
    int max = root->data;
    if (leftMax > max)
        max = leftMax;
    if (rightMax > max)
        max = rightMax;

    return max;
}


int main() {
    
    Node* root1 = createNode(3);
    root1->left = createNode(2);
    root1->right = createNode(5);
    printf("Maximum value (Example 1): %d\n", findMax(root1)); 


    Node* root2 = createNode(1);
    root2->right = createNode(9);
    printf("Maximum value (Example 2): %d\n", findMax(root2));  

    
    free(root1->left);
    free(root1->right);
    free(root1);
    free(root2->right);
    free(root2);

    return 0;
}
