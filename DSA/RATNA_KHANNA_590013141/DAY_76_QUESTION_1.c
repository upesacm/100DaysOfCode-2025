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

int toSumTree(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftSum = toSumTree(root->left);
    int rightSum = toSumTree(root->right);

    int oldValue = root->data;
    root->data = leftSum + rightSum;

    return oldValue + root->data;
}

void printTree(struct Node* root) {
    if (root == NULL)
        return;
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node* nodes[n];
    printf("Enter the nodes data:\n");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        nodes[i] = createNode(val);
    }

    // Manually creating the tree as per the example
    nodes[0]->left = nodes[1];
    nodes[0]->right = nodes[2];
    nodes[1]->left = nodes[3];
    nodes[2]->left = nodes[4];
    nodes[2]->right = nodes[5];

    printf("Original tree in inorder traversal:\n");
    printTree(nodes[0]);
    printf("\n");

    toSumTree(nodes[0]);

    printf("Sum tree in inorder traversal:\n");
    printTree(nodes[0]);
    printf("\n");

    return 0;
}
