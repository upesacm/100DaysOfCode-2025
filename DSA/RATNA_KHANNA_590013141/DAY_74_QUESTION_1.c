#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertLevelOrder(int arr[], int n, int i) {
    if (i < n) {
        struct Node* root = createNode(arr[i]);
        root->left = insertLevelOrder(arr, n, 2*i + 1);
        root->right = insertLevelOrder(arr, n, 2*i + 2);
        return root;
    }
    return NULL;
}

void printNodesAtK(struct Node* root, int k) {
    if (root == NULL) return;
    if (k == 0) {
        printf("%d ", root->data);
        return;
    }
    printNodesAtK(root->left, k - 1);
    printNodesAtK(root->right, k - 1);
}

int main() {
    int n, k;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter tree nodes in level order: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = insertLevelOrder(arr, n, 0);
    printf("Enter distance K: ");
    scanf("%d", &k);
    printf("Nodes at distance %d: ", k);
    printNodesAtK(root, k);
    return 0;
}
