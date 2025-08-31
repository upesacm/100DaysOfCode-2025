#include <stdio.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

int to_sum(struct Node *root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL) {
        int old = root->val;
        root->val = 0;
        return old;
    }

    int left = to_sum(root->left);
    int right = to_sum(root->right);

    int old = root->val;
    root->val = left + right;
    return old + root->val;
}

void print_inorder(struct Node *root) {
    if (root) {
        print_inorder(root->left);
        printf("%d ", root->val);
        print_inorder(root->right);
    }
}

int main() {
    struct Node a = {1, NULL, NULL};
    struct Node b = {2, NULL, NULL};
    struct Node c = {3, NULL, NULL};
    struct Node d = {4, NULL, NULL};
    struct Node e = {5, NULL, NULL};

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;

    printf("Before:\n");
    print_inorder(&a);
    printf("\n");

    to_sum(&a);

    printf("After:\n");
    print_inorder(&a);
    printf("\n");

    return 0;
}
