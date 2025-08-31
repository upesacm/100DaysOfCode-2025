#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Helper struct to return both height and diameter from a recursive call
struct DiameterResult {
    int height;
    int diameter;
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

struct DiameterResult calculateDiameter(struct Node* root) {
    if (root == NULL) {
        struct DiameterResult result = {0, 0};
        return result;
    }
    
    struct DiameterResult leftResult = calculateDiameter(root->left);
    struct DiameterResult rightResult = calculateDiameter(root->right);
    
    int currentHeight = 1 + (leftResult.height > rightResult.height ? leftResult.height : rightResult.height);
    int throughRoot = leftResult.height + rightResult.height;
    int currentDiameter = throughRoot;
    if (leftResult.diameter > currentDiameter) currentDiameter = leftResult.diameter;
    if (rightResult.diameter > currentDiameter) currentDiameter = rightResult.diameter;
    
    struct DiameterResult result = {currentHeight, currentDiameter};
    return result;
}

int findDiameter(struct Node* root) {
    struct DiameterResult result = calculateDiameter(root);
    return result.diameter;
}

int main() {
    printf("Create binary tree (preorder, enter -1 for null nodes):\n");
    struct Node* root = createTree();
    int diameter = findDiameter(root);
    printf("Diameter of tree: %d\n", diameter);
    return 0;
}
