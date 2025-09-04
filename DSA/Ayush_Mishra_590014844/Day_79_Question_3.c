#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int isValidBST(struct Node* root, int min, int max) {
    if (root == NULL) return 1;
    if (root->data <= min || root->data >= max) return 0;
    return isValidBST(root->left, min, root->data) &&
           isValidBST(root->right, root->data, max);
}

int main() {
    int n, val;
    struct Node* root = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d node values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    if (isValidBST(root, INT_MIN, INT_MAX))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
