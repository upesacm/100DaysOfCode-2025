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

int height(struct Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    if (lh == -1) return -1;
    int rh = height(root->right);
    if (rh == -1) return -1;
    if (abs(lh - rh) > 1) return -1;
    return (lh > rh ? lh : rh) + 1;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter tree nodes in level order (-1 for NULL): ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = insertLevelOrder(arr, n, 0);
    if (height(root) == -1) 
        printf("No\n");
    else 
        printf("Yes\n");
    return 0;
}
