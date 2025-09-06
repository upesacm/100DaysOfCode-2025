#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct ListNode {
    int data;
    struct ListNode* next;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return newNode(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

void inorderToList(struct Node* root, struct ListNode** head, struct ListNode** tail) {
    if (root == NULL) return;
    inorderToList(root->left, head, tail);
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->data = root->data;
    node->next = NULL;
    if (*head == NULL) {
        *head = node;
        *tail = node;
    } else {
        (*tail)->next = node;
        *tail = node;
    }
    inorderToList(root->right, head, tail);
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, i, value;
    struct Node* root = NULL;
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    inorderToList(root, &head, &tail);
    printf("Sorted Linked List: ");
    printList(head);
    return 0;
}
