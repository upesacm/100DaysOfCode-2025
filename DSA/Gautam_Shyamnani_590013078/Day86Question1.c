#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) return createnode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Step 1: find min and max horizontal distance
void findMinMax(struct node* root, int* min, int* max, int hd) {
    if (root == NULL) return;
    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;
    findMinMax(root->left, min, max, hd - 1);
    findMinMax(root->right, min, max, hd + 1);
}

// Step 2: print nodes at a given horizontal distance
void printVertical(struct node* root, int hd, int curr_hd) {
    if (root == NULL) return;
    if (hd == curr_hd) printf("%d ", root->data);
    printVertical(root->left, hd, curr_hd - 1);
    printVertical(root->right, hd, curr_hd + 1);
}

// Step 3: vertical order traversal
void verticalOrder(struct node* root) {
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    for (int line = min; line <= max; line++) {
        printf("[ ");
        printVertical(root, line, 0);
        printf("]\n");
    }
}

int main() {
    int n, val;
    struct node* root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nVertical Order Traversal:\n");
    verticalOrder(root);

    return 0;
}
