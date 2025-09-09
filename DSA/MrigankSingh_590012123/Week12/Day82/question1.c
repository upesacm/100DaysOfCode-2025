#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) return NULL;
    
    int mid = start + (end - start) / 2;
    struct Node* root = createNode(arr[mid]);
    
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    
    return root;
}

void printPreorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int n;
    printf("Enter the size of the sorted array: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    struct Node* root = sortedArrayToBST(arr, 0, n - 1);
    
    printf("Preorder traversal of balanced BST: ");
    printPreorder(root);
    printf("\n");
    
    free(arr);
    return 0;
}
