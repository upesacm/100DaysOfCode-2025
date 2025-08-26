#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int areIdentical(struct Node* tree1, struct Node* tree2) {
    if (tree1 == NULL && tree2 == NULL) {
        return 1;
    }
    if (tree1 == NULL || tree2 == NULL) {
        return 0;
    }
    return (tree1->data == tree2->data) &&
           areIdentical(tree1->left, tree2->left) &&
           areIdentical(tree1->right, tree2->right);
}

int main() {
    struct Node* tree1 = newNode(1);
    tree1->left = newNode(2);
    tree1->right = newNode(3);

    struct Node* tree2 = newNode(1);
    tree2->left = newNode(2);
    tree2->right = newNode(3);

    if (areIdentical(tree1, tree2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    struct Node* tree3 = newNode(1);
    tree3->left = newNode(2);

    struct Node* tree4 = newNode(1);
    tree4->right = newNode(2);

    if (areIdentical(tree3, tree4)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
