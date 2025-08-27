#include <stdio.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int find_max(struct Node *root) {
    if (root == NULL)
        return -1000000;  // Very small number
    int l = find_max(root->left);
    int r = find_max(root->right);
    return max(root->val, max(l, r));
}
int main() {
    struct Node a = {3, NULL, NULL};
    struct Node b = {2, NULL, NULL};
    struct Node c = {5, NULL, NULL};
    a.left = &b;
    a.right = &c;

    printf("Max: %d\n", find_max(&a)); 
    return 0;
}
