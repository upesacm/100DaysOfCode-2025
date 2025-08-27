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
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    int choice;
    printf("Insert %d to left(1) or right(2) of %d: ", data, root->data);
    scanf("%d", &choice);
    if (choice == 1) root->left = insertNode(root->left, data);
    else root->right = insertNode(root->right, data);
    return root;
}

int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, val, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Tree is empty\n");
        return 0;
    }
    printf("Enter value for root: ");
    scanf("%d", &val);
    root = createNode(val);
    for (i = 1; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        insertNode(root, val);
    }
    printf("Total number of nodes in the tree: %d\n", countNodes(root));
    return 0;
}
