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

struct Node* createTree() {
    int data;
    printf("Enter node value (-1 for null): ");
    scanf("%d", &data);
    if (data == -1) return NULL;
    
    struct Node* root = createNode(data);
    printf("Enter left subtree of %d (BST order)\n", data);
    root->left = createTree();
    printf("Enter right subtree of %d (BST order)\n", data);
    root->right = createTree();
    return root;
}

void bstToLinkedListUtil(struct Node* root, struct Node** head, struct Node** prev) {
    if (root == NULL) return;
    
    bstToLinkedListUtil(root->left, head, prev);
    
    if (*prev == NULL) {
        *head = root;
    } else {
        (*prev)->right = root;
        root->left = NULL;
    }
    *prev = root;
    
    bstToLinkedListUtil(root->right, head, prev);
}

struct Node* bstToLinkedList(struct Node* root) {
    struct Node* head = NULL;
    struct Node* prev = NULL;
    bstToLinkedListUtil(root, &head, &prev);
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->right != NULL) printf(" -> ");
        head = head->right;
    }
    printf("\n");
}

int main() {
    printf("Create BST (preorder, enter -1 for null nodes, maintain BST property):\n");
    struct Node* root = createTree();
    struct Node* head = bstToLinkedList(root);
    printf("Sorted linked list: ");
    printList(head);
    return 0;
}
