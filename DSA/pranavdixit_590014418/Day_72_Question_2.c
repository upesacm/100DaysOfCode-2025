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
    node->left = node->right = NULL;
    return node;
}

int isIdentical(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL) return 1;
    if (t1 == NULL || t2 == NULL) return 0;
    return (t1->data == t2->data) &&
           isIdentical(t1->left, t2->left) &&
           isIdentical(t1->right, t2->right);
}

int main() {
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);

    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);

    printf("Trees identical? %s\n", isIdentical(root1, root2) ? "Yes" : "No"); // Yes

    struct Node* root3 = newNode(1);
    root3->left = newNode(2);

    struct Node* root4 = newNode(1);
    root4->right = newNode(2);

    printf("Trees identical? %s\n", isIdentical(root3, root4) ? "Yes" : "No"); // No

    return 0;
}
