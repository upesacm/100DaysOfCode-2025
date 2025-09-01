#include <stdio.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int height(struct Node *root) {
    if (root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    return 1 + max(l, r);  // ✅ Fixed: include current node
}

int main() {
    struct Node a = {1, NULL, NULL};
    struct Node b = {2, NULL, NULL};
    struct Node c = {3, NULL, NULL};
    a.left = &b;
    b.left = &c;

    printf("Height: %d\n", height(&a));  // Output: 3
    return 0;
}
