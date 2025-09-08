#include <stdio.h>
#include <stdlib.h>


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


int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);

    printf("Total nodes = %d\n", countNodes(root));  

    struct Node* root2 = NULL;
    root2 = insert(root2, 8);
    insert(root2, 6);
    insert(root2, 10);
    insert(root2, 4);

    printf("Total nodes = %d\n", countNodes(root2));  

    return 0;
}

