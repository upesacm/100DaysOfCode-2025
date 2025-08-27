#include <stdio.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

int sum(struct Node *root) {
    if (root == NULL)
        return 0;
    return root->val + sum(root->left) + sum(root->right);
}

// Example usage
int main() {
    struct Node a = {1, NULL, NULL};
    struct Node b = {2, NULL, NULL};
    struct Node c = {3, NULL, NULL};
    a.left = &b;
    a.right = &c;

    printf("Sum: %d\n", sum(&a));  // Output: 6
    return 0;
}

