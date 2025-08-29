#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
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
    int k;
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Enter distance K from root: ");
    scanf("%d", &k);

    printf("Nodes at distance %d: ", k);
    printKDistance(root, k);
    printf("\n");
    return 0;
}
