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
    if (i < n && arr[i] != -1) {
        struct Node* root = createNode(arr[i]);
        root->left = insertLevelOrder(arr, n, 2*i + 1);
        root->right = insertLevelOrder(arr, n, 2*i + 2);
        return root;
    }
    return NULL;
}

void printPath(int path[], int pathLen) {
    for (int i = 0; i < pathLen; i++) {
        printf("%d", path[i]);
        if (i != pathLen - 1) printf("->");
    }
    printf("\n");
}

void rootToLeaf(struct Node* root, int path[], int pathLen) {
    if (root == NULL) return;
    path[pathLen] = root->data;
    pathLen++;
    if (root->left == NULL && root->right == NULL) {
        printPath(path, pathLen);
    } else {
        rootToLeaf(root->left, path, pathLen);
        rootToLeaf(root->right, path, pathLen);
    }
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter tree nodes in level order (-1 for NULL): ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = insertLevelOrder(arr, n, 0);
    int path[1000];
    printf("Root to Leaf Paths:\n");
    rootToLeaf(root, path, 0);
    return 0;
}
