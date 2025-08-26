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
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    int choice;
    printf("Insert %d to left(1) or right(2) of %d: ", data, root->data);
    scanf("%d", &choice);
    if (choice == 1) root->left = insertNode(root->left, data);
    else root->right = insertNode(root->right, data);
    return root;
}

int areIdentical(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL) return 1;
    if (root1 == NULL || root2 == NULL) return 0;
    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

int main() {
    struct Node* root1 = NULL;
    struct Node* root2 = NULL;
    int n1, n2, val, i;
    printf("Enter number of nodes in Tree1: ");
    scanf("%d", &n1);
    if (n1 > 0) {
        printf("Enter value for root of Tree1: ");
        scanf("%d", &val);
        root1 = createNode(val);
        for (i = 1; i < n1; i++) {
            printf("Enter value for node %d: ", i + 1);
            scanf("%d", &val);
            insertNode(root1, val);
        }
    }
    printf("Enter number of nodes in Tree2: ");
    scanf("%d", &n2);
    if (n2 > 0) {
        printf("Enter value for root of Tree2: ");
        scanf("%d", &val);
        root2 = createNode(val);
        for (i = 1; i < n2; i++) {
            printf("Enter value for node %d: ", i + 1);
            scanf("%d", &val);
            insertNode(root2, val);
        }
    }
    if (areIdentical(root1, root2)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
