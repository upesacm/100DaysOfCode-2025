#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

TreeNode* insert(TreeNode* root, int val) {
    if (!root) {
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->val = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void inorder(TreeNode* root, ListNode** head, ListNode** tail) {
    if (!root) return;
    inorder(root->left, head, tail);
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = root->val;
    newNode->next = NULL;
    if (!*head) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
    inorder(root->right, head, tail);
}

int main() {
    int n, val;
    scanf("%d", &n);
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    ListNode *head = NULL, *tail = NULL;
    inorder(root, &head, &tail);
    ListNode* temp = head;
    while (temp) {
        printf("%d", temp->val);
        if (temp->next) printf("->");
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
