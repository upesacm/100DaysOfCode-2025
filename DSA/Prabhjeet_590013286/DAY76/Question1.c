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

int toSumTree(struct Node* root) {
    if (root == NULL)
        return 0;

    int old_val = root->data;

    int left_sum = toSumTree(root->left);
    int right_sum = toSumTree(root->right);

    root->data = left_sum + right_sum;

    return root->data + old_val;
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
