#include <stdio.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

int range_sum(struct Node *root, int L, int R) {
    if (root == NULL)
        return 0;

    if (root->val < L)
        return range_sum(root->right, L, R);
    if (root->val > R)
        return range_sum(root->left, L, R);

    return root->val + range_sum(root->left, L, R) + range_sum(root->right, L, R);
}

// Example usage
int main() {
    struct Node a = {10, NULL, NULL};
    struct Node b = {5, NULL, NULL};
    struct Node c = {15, NULL, NULL};
    struct Node d = {3, NULL, NULL};
    struct Node e = {7, NULL, NULL};
    struct Node f = {18, NULL, NULL};

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;

    int L = 7, R = 15;
    printf("Range Sum: %d\n", range_sum(&a, L, R));  // Output: 32
    return 0;
}
