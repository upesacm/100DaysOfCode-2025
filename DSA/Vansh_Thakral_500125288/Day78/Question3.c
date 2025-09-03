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


int findMin(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return -1;
    }
    struct Node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current->key;
}


int findMax(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return -1;
    }
    struct Node* current = root;
    while (current->right != NULL)
        current = current->right;
    return current->key;
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);

    printf("Min = %d, Max = %d\n", findMin(root), findMax(root));

    struct Node* single = newNode(5);
    printf("Min = %d, Max = %d\n", findMin(single), findMax(single));

    return 0;
}
