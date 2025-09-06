#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct ListNode {
    int val;
    struct ListNode* next;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else if (val > root->val) root->right = insert(root->right, val);
    return root;
}

void inorderToList(struct Node* root, struct ListNode** headRef, struct ListNode** tailRef) {
    if (root == NULL) return;
    
    inorderToList(root->left, headRef, tailRef);

    struct ListNode* newLNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newLNode->val = root->val;
    newLNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = *tailRef = newLNode;
    } else {
        (*tailRef)->next = newLNode;
        *tailRef = newLNode;
    }

    inorderToList(root->right, headRef, tailRef);
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);

    struct ListNode* head = NULL, *tail = NULL;
    inorderToList(root, &head, &tail);

    printf("BST converted to Sorted Linked List:\n");
    printList(head);

    return 0;
}
