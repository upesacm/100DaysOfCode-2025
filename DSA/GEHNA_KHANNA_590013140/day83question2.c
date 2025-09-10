#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void serialize(struct TreeNode* root, char* buf) {
    if (!root) return;
    char tmp[20];
    sprintf(tmp, "%d,", root->val);
    strcat(buf, tmp);
    serialize(root->left, buf);
    serialize(root->right, buf);
}

struct TreeNode* build(int* preorder, int* idx, int n, int min, int max) {
    if (*idx >= n) return NULL;
    int val = preorder[*idx];
    if (val < min || val > max) return NULL;
    (*idx)++;
    struct TreeNode* root = newNode(val);
    root->left = build(preorder, idx, n, min, val);
    root->right = build(preorder, idx, n, val, max);
    return root;
}

void inorder(struct TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    int n, val; scanf("%d", &n);
    struct TreeNode* root = NULL;

    // build BST by insertion
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct TreeNode* node = newNode(val);
        if (!root) root = node;
        else {
            struct TreeNode* cur = root;
            while (1) {
                if (val < cur->val) {
                    if (!cur->left) { cur->left = node; break; }
                    cur = cur->left;
                } else {
                    if (!cur->right) { cur->right = node; break; }
                    cur = cur->right;
                }
            }
        }
    }

    char buf[1000] = "";
    serialize(root, buf);
    if (strlen(buf) > 0) buf[strlen(buf) - 1] = '\0';
    printf("Serialized: %s\n", buf);

    int preorder[100], idx = 0, cnt = 0;
    char* token = strtok(buf, ",");
    while (token) {
        preorder[cnt++] = atoi(token);
        token = strtok(NULL, ",");
    }

    idx = 0;
    struct TreeNode* newRoot = build(preorder, &idx, cnt, INT_MIN, INT_MAX);
    printf("Deserialized Inorder: ");
    inorder(newRoot);
    return 0;
}
