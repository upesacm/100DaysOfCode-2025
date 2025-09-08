#include <stdio.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

void print_range(struct Node *root, int L, int R) {
    if (root == NULL)
        return;

    if (root->val > L)
        print_range(root->left, L, R);

    if (root->val >= L && root->val <= R)
        printf("%d ", root->val);

    if (root->val < R)
        print_range(root->right, L, R);
}


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
    printf("Nodes in range [%d, %d]: ", L, R);
    print_range(&a, L, R);  
    printf("\n");
    return 0;
}
