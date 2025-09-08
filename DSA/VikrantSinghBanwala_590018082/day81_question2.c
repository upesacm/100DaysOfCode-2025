#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

void inorderFlatten(TreeNode* root, ListNode** head, ListNode** tail) {
    if (!root) return;
    inorderFlatten(root->left, head, tail);
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = root->val;
    node->next = NULL;
    if (!*head) {
        *head = node;
        *tail = node;
    } else {
        (*tail)->next = node;
        *tail = node;
    }
    inorderFlatten(root->right, head, tail);
}

ListNode* bstToSortedList(TreeNode* root) {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    inorderFlatten(root, &head, &tail);
    return head;
}

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void printList(ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    TreeNode* root1 = newNode(4);
    root1->left = newNode(2);
    root1->right = newNode(6);
    root1->left->left = newNode(1);
    root1->left->right = newNode(3);
    root1->right->left = newNode(5);
    root1->right->right = newNode(7);
    ListNode* list1 = bstToSortedList(root1);
    printList(list1);

    TreeNode* root2 = newNode(2);
    root2->left = newNode(1);
    root2->right = newNode(3);
    ListNode* list2 = bstToSortedList(root2);
    printList(list2);

    return 0;
}