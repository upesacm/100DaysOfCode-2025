#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

int search(struct Node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    else if (key < root->data) return search(root->left, key);
    else return search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int n, val, key;

    printf("Enter number of elements to insert in BST: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter key to search: ");
    scanf("%d", &key);

    if (search(root, key))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
