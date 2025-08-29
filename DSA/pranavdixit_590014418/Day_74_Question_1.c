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

void printKDistance(struct Node* root, int k) {
    if (root == NULL) return;
    if (k == 0) {
        printf("%d ", root->data);
        return;
    }
    printKDistance(root->left, k - 1);
    printKDistance(root->right, k - 1);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Nodes at distance 2: ");
    printKDistance(root, 2);  // 4 5
    printf("\n");

    return 0;
}
