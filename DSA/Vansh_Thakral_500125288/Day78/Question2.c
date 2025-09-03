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

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);

    printf("Tree inorder before insertion:\n");
    inorder(root);
    printf("\n");

    insert(root, 4);

    printf("Tree inorder after insertion:\n");
    inorder(root);
    printf("\n");

    return 0;
}
