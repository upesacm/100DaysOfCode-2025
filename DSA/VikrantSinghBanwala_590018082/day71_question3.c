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

int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->left->left = newNode(3);

    printf("%d\n", height(root1));

    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);

    printf("%d\n", height(root2));

    return 0;
}
