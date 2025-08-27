#include <stdio.h>
#include <stdlib.h>

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

int sumOfNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->value + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main() {
    struct Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    
    printf("%d\n", sumOfNodes(root1));

    struct Node* root2 = createNode(10);
    root2->left = createNode(5);
    
    printf("%d\n", sumOfNodes(root2));

    return 0;
}
