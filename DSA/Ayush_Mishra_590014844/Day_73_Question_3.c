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

int findMax(struct Node* root) {
    if (root == NULL) return -2147483648;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    int max = root->data;
    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;
    return max;
}

int main() {
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node* tree[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        tree[i] = createNode(val);
    }

    for (int i = 0; i < n; i++) {
        int l, r;
        printf("Enter left and right child indices of node %d (-1 for NULL): ", i + 1);
        scanf("%d %d", &l, &r);
        if (l != -1) tree[i]->left = tree[l];
        if (r != -1) tree[i]->right = tree[r];
    }

    printf("Maximum value in tree: %d\n", findMax(tree[0]));
    return 0;
}
