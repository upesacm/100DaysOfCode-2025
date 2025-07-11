#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;
    ListNode* temp;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    if (fast != NULL) {
        slow = slow->next;
    }

    while (slow != NULL) {
        if (prev->val != slow->val) {
            return false;
        }
        prev = prev->next;
        slow = slow->next;
    }

    return true;
}

ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void freeList(ListNode* head) {
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

ListNode* inputList() {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    int value;
    printf("Enter values for the linked list (end with -1): ");
    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        ListNode* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    ListNode* head = inputList();
    printf("Is the linked list a palindrome? %s\n", isPalindrome(head) ? "true" : "false");
    freeList(head);
    return 0;
}
