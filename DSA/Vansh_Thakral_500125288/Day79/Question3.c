#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}


struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL) return 1;
    if (root->key <= min || root->key >= max) return 0;
    return isBSTUtil(root->left, min, root->key) &&
           isBSTUtil(root->right, root->key, max);
}


int isValidBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {

    struct Node* root1 = NULL;
    root1 = insert(root1, 2);
    insert(root1, 1);
    insert(root1, 3);

    if (isValidBST(root1))
        printf("Yes\n");
    else
        printf("No\n");


    struct Node* root2 = newNode(5);
    root2->left = newNode(1);
    root2->right = newNode(4);
    root2->right->left = newNode(3);
    root2->right->right = newNode(6);

    if (isValidBST(root2))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

