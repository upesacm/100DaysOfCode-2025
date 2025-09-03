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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int checkBalanced(struct Node* root, int* height) {
    if (root == NULL) {
        *height = 0;
        return 1;
    }
    int lh = 0, rh = 0;
    int l = checkBalanced(root->left, &lh);
    int r = checkBalanced(root->right, &rh);
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) > 1)
        return 0;
    return l && r;
}

struct Node* buildTree(int n) {
    if (n == 0) return NULL;
    int data, leftCount, rightCount;
    scanf("%d", &data);
    struct Node* root = newNode(data);
    scanf("%d", &leftCount);
    root->left = buildTree(leftCount);
    scanf("%d", &rightCount);
    root->right = buildTree(rightCount);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* root = buildTree(n);
    int height = 0;
    if (checkBalanced(root, &height))
        printf("Yes");
    else
        printf("No");
    return 0;
}
