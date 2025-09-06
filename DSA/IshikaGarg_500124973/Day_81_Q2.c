#include <stdio.h>
#include <stdlib.h>

// BST Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Linked List Node
struct ListNode {
    int data;
    struct ListNode* next;
};

// Create new BST node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (!root) return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Create new List node
struct ListNode* newListNode(int data) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// Inorder traversal + append to list
void inorderToList(struct Node* root, struct ListNode** head, struct ListNode** tail) {
    if (!root) return;

    inorderToList(root->left, head, tail);

    struct ListNode* newNodeL = newListNode(root->data);
    if (!*head) {
        *head = *tail = newNodeL;
    } else {
        (*tail)->next = newNodeL;
        *tail = newNodeL;
    }

    inorderToList(root->right, head, tail);
}

// Print Linked List
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);

    struct ListNode* head = NULL, *tail = NULL;
    inorderToList(root, &head, &tail);

    printf("Sorted Linked List: ");
    printList(head); // Expected: 1 2 3 4 5 6 7
    return 0;
}

