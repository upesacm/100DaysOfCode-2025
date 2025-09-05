#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void convertBSTHelper(struct Node* root, int* sum) {
    if (!root) return;
    convertBSTHelper(root->right, sum);
    *sum += root->val;
    root->val = *sum;
    convertBSTHelper(root->left, sum);
}

struct Node* convertBST(struct Node* root) {
    int sum = 0;
    convertBSTHelper(root, &sum);
    return root;
}

int main() {
    struct Node* root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(13);

    root = convertBST(root);
    inorder(root);
    return 0;
}
