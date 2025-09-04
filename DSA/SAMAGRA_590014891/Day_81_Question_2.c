#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (!root) return newNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void inorderToList(struct TreeNode* root, struct ListNode** head, struct ListNode** tail) {
    if (!root) return;
    inorderToList(root->left, head, tail);
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = root->val;
    node->next = NULL;
    if (!*head) *head = node;
    else (*tail)->next = node;
    *tail = node;
    inorderToList(root->right, head, tail);
}

struct ListNode* bstToSortedList(struct TreeNode* root) {
    struct ListNode* head = NULL, *tail = NULL;
    inorderToList(root, &head, &tail);
    return head;
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct TreeNode* root = NULL;
    int values[] = {4,2,6,1,3,5,7};
    for (int i = 0; i < 7; i++) root = insert(root, values[i]);

    struct ListNode* head = bstToSortedList(root);
    printf("Sorted Linked List: ");
    printList(head);
    return 0;
}
