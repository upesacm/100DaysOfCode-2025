#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct ListNode {
    int val;
    struct ListNode* next;
};

struct TreeNode* newTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return newTreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

struct ListNode* head = NULL;
struct ListNode* tail = NULL;

void bstToSortedList(struct TreeNode* root) {
    if (root == NULL) return;
    bstToSortedList(root->left);
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = root->val;
    newNode->next = NULL;
    if (head == NULL) head = tail = newNode;
    else { tail->next = newNode; tail = newNode; }
    bstToSortedList(root->right);
}

void printList(struct ListNode* node) {
    while (node) {
        printf("%d", node->val);
        if (node->next) printf(" -> ");
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct TreeNode* root = NULL;
    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    bstToSortedList(root);
    printList(head);
    return 0;
}
