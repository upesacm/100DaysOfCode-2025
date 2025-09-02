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

void mirror(struct Node* root) {
    if (root == NULL) return;
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n, i, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct Node* nodes[n];
    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        nodes[i] = createNode(val);
    }
    for (i = 0; i < n; i++) {
        int l, r;
        printf("Enter left and right child indices of node %d (-1 for NULL): ", i + 1);
        scanf("%d %d", &l, &r);
        if (l != -1) nodes[i]->left = nodes[l];
        if (r != -1) nodes[i]->right = nodes[r];
    }
    mirror(nodes[0]);
    printf("Inorder traversal of mirrored tree: ");
    inorder(nodes[0]);
    return 0;
}
