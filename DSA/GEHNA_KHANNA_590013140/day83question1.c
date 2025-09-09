#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct Pair {
    struct TreeNode* node;
    int hd;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    t->val = val;
    t->left = t->right = NULL;
    return t;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (!root) return newNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void verticalOrder(struct TreeNode* root) {
    if (!root) return;
    struct Pair queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = (struct Pair){root, 0};

    int minHD = 0, maxHD = 0;
    int map[201][201], count[201];
    for (int i = 0; i < 201; i++) count[i] = 0;

    while (front < rear) {
        struct Pair p = queue[front++];
        int hd = p.hd;
        map[hd + 100][count[hd + 100]++] = p.node->val;
        if (p.node->left) queue[rear++] = (struct Pair){p.node->left, hd - 1};
        if (p.node->right) queue[rear++] = (struct Pair){p.node->right, hd + 1};
        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;
    }

    for (int i = minHD; i <= maxHD; i++) {
        printf("[");
        for (int j = 0; j < count[i + 100]; j++) {
            printf("%d", map[i + 100][j]);
            if (j < count[i + 100] - 1) printf(",");
        }
        printf("] ");
    }
    printf("\n");
}

int main() {
    int n, val; scanf("%d", &n);
    struct TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    verticalOrder(root);
    return 0;
}
