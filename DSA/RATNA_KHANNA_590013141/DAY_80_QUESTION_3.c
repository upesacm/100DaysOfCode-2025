#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

int count = 0, result = -1;

void kthSmallestUtil(struct Node* root, int k) {
    if (root == NULL || result != -1) return;
    kthSmallestUtil(root->left, k);
    count++;
    if (count == k) {
        result = root->data;
        return;
    }
    kthSmallestUtil(root->right, k);
}

int kthSmallest(struct Node* root, int k) {
    count = 0;
    result = -1;
    kthSmallestUtil(root, k);
    return result;
}

int main() {
    int n, value, i, k;
    struct Node* root = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter tree values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("Enter value of K: ");
    scanf("%d", &k);
    int ans = kthSmallest(root, k);
    if (ans != -1)
        printf("Kth smallest element: %d", ans);
    else
        printf("K is larger than number of nodes in the tree");
    return 0;
}
