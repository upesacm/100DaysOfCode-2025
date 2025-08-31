#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create() {
    int x;
    scanf("%d", &x);
    if (x == -1) {
        return NULL;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->left = create();
    newNode->right = create();
    return newNode;
}

int isIdentical(struct Node* a, struct Node* b) {
    if (a == NULL && b == NULL) {
        return 1;
    }
    if (a == NULL || b == NULL) {
        return 0;
    }
    if (a->data != b->data) {
        return 0;
    }
    return isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
}

int main() {
    printf("Enter first tree in preorder (-1 for null):\n");
    struct Node* tree1 = create();
    printf("Enter second tree in preorder (-1 for null):\n");
    struct Node* tree2 = create();
    if (isIdentical(tree1, tree2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
