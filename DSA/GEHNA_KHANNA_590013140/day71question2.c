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

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    int ch;
    printf("Insert %d to left(1) or right(2) of %d: ", data, root->data);
    scanf("%d", &ch);
    if (ch == 1) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

int countLeaves(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    int n, val;
    struct Node* root = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        if (root == NULL) root = newNode(val);
        else root = insert(root, val);
    }
    printf("%d\n", countLeaves(root));
    return 0;
}
