#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* buildTree(int n) {
    struct Node* nodes[n];
    int i, val, l, r;
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        nodes[i] = newNode(val);
    }
    for (i = 0; i < n; i++) {
        scanf("%d %d", &l, &r);
        if (l != -1) nodes[i]->left = nodes[l];
        if (r != -1) nodes[i]->right = nodes[r];
    }
    return nodes[0];
}

int max(int a, int b) {
    return a > b ? a : b;
}

int diameterUtil(struct Node* root, int* height) {
    if (!root) {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ld = diameterUtil(root->left, &lh);
    int rd = diameterUtil(root->right, &rh);
    *height = max(lh, rh) + 1;
    return max(max(ld, rd), lh + rh + 1);
}

int diameter(struct Node* root) {
    int height = 0;
    return diameterUtil(root, &height);
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* root = buildTree(n);
    printf("%d\n", diameter(root));
    return 0;
}
