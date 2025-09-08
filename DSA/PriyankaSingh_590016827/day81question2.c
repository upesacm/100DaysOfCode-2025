#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Definition for a linked list node.
typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

// Global head and tail of the linked list
ListNode* head = NULL;
ListNode* tail = NULL;

// Helper function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper function to create a new list node
ListNode* createListNode(int data) {
    ListNode* newListNode = (ListNode*)malloc(sizeof(ListNode));
    newListNode->data = data;
    newListNode->next = NULL;
    return newListNode;
}

// BST to Sorted Linked List
void bstToSortedList(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    bstToSortedList(root->left);
    
    ListNode* newListNode = createListNode(root->data);
    if (head == NULL) {
        head = tail = newListNode;
    } else {
        tail->next = newListNode;
        tail = newListNode;
    }
    
    bstToSortedList(root->right);
}

// Helper function to print the linked list
void printList(ListNode* node) {
    while (node != NULL) {
        printf("%d", node->data);
        if (node->next != NULL) {
            printf(" -> ");
        }
        node = node->next;
    }
    printf("\n");
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(4);
    root1->left = createNode(2);
    root1->right = createNode(6);
    root1->left->left = createNode(1);
    root1->left->right = createNode(3);
    root1->right->left = createNode(5);
    root1->right->right = createNode(7);
    head = tail = NULL;
    bstToSortedList(root1);
    printf("Output List: ");
    printList(head);

    // Example 2
    TreeNode* root2 = createNode(2);
    root2->left = createNode(1);
    root2->right = createNode(3);
    head = tail = NULL;
    bstToSortedList(root2);
    printf("Output List: ");
    printList(head);

    return 0;
}
