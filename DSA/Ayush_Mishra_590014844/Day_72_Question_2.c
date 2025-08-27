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

int isIdentical(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL) return 1;
    if (root1 == NULL || root2 == NULL) return 0;
    return (root1->data == root2->data) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

int main() {
    int n, i, val;
    printf("Enter number of nodes in Tree 1: ");
    scanf("%d", &n);
    struct Node* tree1[n];
    for (i = 0; i < n; i++) {
        printf("Enter value for node %d of Tree 1: ", i + 1);
        scanf("%d", &val);
        tree1[i] = createNode(val);
    }
    for (i = 0; i < n; i++) {
        int l, r;
        printf("Enter left and right child indices of node %d in Tree 1 (-1 for NULL): ", i + 1);
        scanf("%d %d", &l, &r);
        if (l != -1) tree1[i]->left = tree1[l];
        if (r != -1) tree1[i]->right = tree1[r];
    }

    printf("Enter number of nodes in Tree 2: ");
    scanf("%d", &n);
    struct Node* tree2[n];
    for (i = 0; i < n; i++) {
        printf("Enter value for node %d of Tree 2: ", i + 1);
        scanf("%d", &val);
        tree2[i] = createNode(val);
    }
    for (i = 0; i < n; i++) {
        int l, r;
        printf("Enter left and right child indices of node %d in Tree 2 (-1 for NULL): ", i + 1);
        scanf("%d %d", &l, &r);
        if (l != -1) tree2[i]->left = tree2[l];
        if (r != -1) tree2[i]->right = tree2[r];
    }

    if (isIdentical(tree1[0], tree2[0]))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
