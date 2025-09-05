#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return newNode(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

void printInRange(struct Node* root, int L, int R) {
    if (root == NULL) return;
    if (root->data > L) printInRange(root->left, L, R);
    if (root->data >= L && root->data <= R) printf("%d ", root->data);
    if (root->data < R) printInRange(root->right, L, R);
}

int main() {
    int n, i, value, L, R;
    struct Node* root = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("Enter L and R: ");
    scanf("%d %d", &L, &R);
    printf("Nodes in range [%d, %d]: ", L, R);
    printInRange(root, L, R);
    printf("\n");
    return 0;
}
