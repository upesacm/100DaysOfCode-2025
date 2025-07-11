#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    while (head != NULL) {
        struct ListNode* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return true;

    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* secondHalf = reverseList(slow);
    struct ListNode* firstHalf = head;

    struct ListNode* temp = secondHalf;
    while (temp) {
        if (temp->val != firstHalf->val)
            return false;
        temp = temp->next;
        firstHalf = firstHalf->next;
    }

    return true;
}
struct ListNode* newNode(int data) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = data;
    node->next = NULL;
    return node;
}

int main() {
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(1);
    head->next->next->next = newNode(1);
    head->next->next->next->next = newNode(2);
    head->next->next->next->next->next = newNode(1);

    if (isPalindrome(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
