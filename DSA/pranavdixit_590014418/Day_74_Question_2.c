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

int height(struct Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    if (lh == -1) return -1;
    int rh = height(root->right);
    if (rh == -1) return -1;
    if (abs(lh - rh) > 1) return -1;
    return (lh > rh ? lh : rh) + 1;
}

int isBalanced(struct Node* root) {
    return height(root) != -1;
}

int main() {
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->left->left = newNode(3);
    printf("Balanced? %s\n", isBalanced(root1) ? "Yes" : "No");  // No

    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    printf("Balanced? %s\n", isBalanced(root2) ? "Yes" : "No");  // Yes

    return 0;
}
