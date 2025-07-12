#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->val = val;
    n->next = NULL;
    return n;
}

struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *next;
    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

int isPalindrome(struct Node* head) {
    if (!head || !head->next) return 1;
    struct Node *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct Node *second = reverse(slow->next), *first = head;
    while (second) {
        if (first->val != second->val) return 0;
        first = first->next;
        second = second->next;
    }
    return 1;
}

int main() {
    int n, x;
    struct Node *head = NULL, *tail = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* temp = newNode(x);
        if (!head) head = tail = temp;
        else tail->next = temp, tail = temp;
    }
    printf(isPalindrome(head) ? "true\n" : "false\n");
    return 0;
}
