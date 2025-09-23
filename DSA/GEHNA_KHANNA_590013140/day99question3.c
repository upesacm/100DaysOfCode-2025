#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int max(int a, int b) { return a > b ? a : b; }

int maxPathUtil(struct Node* root, int *res) {
    if (!root) return 0;
    int l = maxPathUtil(root->left, res);
    int r = maxPathUtil(root->right, res);
    int max_single = max(max(l, r) + root->val, root->val);
    int max_top = max(max_single, l + r + root->val);
    if (*res < max_top) *res = max_top;
    return max_single;
}

int maxPathSum(struct Node* root) {
    int res = INT_MIN;
    maxPathUtil(root, &res);
    return res;
}

struct Node* buildTree(int n) {
    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        if (val == -1) nodes[i] = NULL;
        else nodes[i] = newNode(val);
    }
    for (int i = 0, j = 1; j < n; i++) {
        if (nodes[i]) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }
    return nodes[0];
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* root = buildTree(n);
    printf("%d\n", maxPathSum(root));
    return 0;
}
