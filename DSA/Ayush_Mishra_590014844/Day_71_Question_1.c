#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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

    printf("Enter left and right child indices (-1 for NULL) for each node:\n");
    for (int i = 0; i < n; i++) {
        int l, r;
        printf("Node %d (%d): ", i, nodes[i]->data);
        scanf("%d %d", &l, &r);
        if (l != -1) nodes[i]->left = nodes[l];
        if (r != -1) nodes[i]->right = nodes[r];
    }

    printf("Inorder Traversal: ");
    inorder(nodes[0]);
    printf("\n");
    return 0;
}
