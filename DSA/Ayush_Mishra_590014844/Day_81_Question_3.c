#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* insert(Node* root, int val) {
    if (!root) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void printRange(Node* root, int L, int R) {
    if (!root) return;
    if (root->val > L)
        printRange(root->left, L, R);
    if (root->val >= L && root->val <= R)
        printf("%d ", root->val);
    if (root->val < R)
        printRange(root->right, L, R);
}

int main() {
    int n, val, L, R;
    scanf("%d", &n);
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    scanf("%d %d", &L, &R);
    printRange(root, L, R);
    printf("\n");
    return 0;
}
