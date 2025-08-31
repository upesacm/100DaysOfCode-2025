#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findMax(struct Node* root) {
    if (root == NULL) {
        return INT_MIN; 
    }
    int maxValue = root->value;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    
    if (leftMax > maxValue) {
        maxValue = leftMax;
    }
    if (rightMax > maxValue) {
        maxValue = rightMax;
    }
    
    return maxValue;
}

int main() {
    struct Node* root1 = createNode(3);
    root1->left = createNode(2);
    root1->right = createNode(5);
    
    printf("%d\n", findMax(root1));

    struct Node* root2 = createNode(1);
    root2->right = createNode(9);
    
    printf("%d\n", findMax(root2));

    return 0;
}
