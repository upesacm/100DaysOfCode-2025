#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int n) {
    if (n == 0) return NULL;
    struct Node** nodes = (struct Node**)malloc((n+1)*sizeof(struct Node*));
    for (int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        if (val == -1) nodes[i] = NULL;
        else nodes[i] = newNode(val);
    }
    for (int i = 1; i <= n; i++) {
        if (nodes[i]) {
            int l = 2*i, r = 2*i+1;
            if (l <= n) nodes[i]->left = nodes[l];
            if (r <= n) nodes[i]->right = nodes[r];
        }
    }
    struct Node* root = nodes[1];
    free(nodes);
    return root;
}

int countLeaves(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d node values in level order (-1 for NULL):\n", n);
    struct Node* root = buildTree(n);
    int result = countLeaves(root);
    printf("Number of leaf nodes: %d\n", result);
    return 0;
}
