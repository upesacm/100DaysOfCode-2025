#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

int checkHeight(struct Node* root) {
    if (root == NULL) return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;

    if (abs(leftHeight - rightHeight) > 1) return -1;

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

bool isBalanced(struct Node* root) {
    return (checkHeight(root) != -1);
}

int main() {
   
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->left->left = newNode(3);

    printf("Tree 1 Balanced? %s\n", isBalanced(root1) ? "Yes" : "No"); 

 
    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);

    printf("Tree 2 Balanced? %s\n", isBalanced(root2) ? "Yes" : "No"); 

    return 0;
}

