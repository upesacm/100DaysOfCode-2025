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

int sumNodes(struct Node* root) {
    if (root == NULL) return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

int main() {
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        nodes[i] = createNode(val);
    }

    for (int i = 0; i < n; i++) {
        int l, r;
        printf("Enter left and right child indices of node %d (-1 for NULL): ", i + 1);
        scanf("%d %d", &l, &r);
        if (l != -1) nodes[i]->left = nodes[l];
        if (r != -1) nodes[i]->right = nodes[r];
    }

    printf("Sum of all nodes: %d\n", sumNodes(nodes[0]));
    return 0;
}
