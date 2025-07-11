#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct ListNode {
    int val;
    struct ListNode* next;
};

// Create new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to get length of a list
int getLength(struct ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Pad the shorter list with leading zeros
struct ListNode* padZeros(struct ListNode* head, int padding) {
    for (int i = 0; i < padding; i++) {
        struct ListNode* newNode = createNode(0);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Recursive addition function
struct ListNode* addListsHelper(struct ListNode* l1, struct ListNode* l2, int* carry) {
    if (!l1 && !l2) return NULL;

    struct ListNode* nextNode = addListsHelper(l1->next, l2->next, carry);

    int sum = l1->val + l2->val + *carry;
    *carry = sum / 10;
    int digit = sum % 10;

    struct ListNode* result = createNode(digit);
    result->next = nextNode;

    return result;
}

// Main function to add two lists
struct ListNode* addTwoLists(struct ListNode* l1, struct ListNode* l2) {
    int len1 = getLength(l1);
    int len2 = getLength(l2);

    // Pad shorter list
    if (len1 < len2)
        l1 = padZeros(l1, len2 - len1);
    else
        l2 = padZeros(l2, len1 - len2);

    int carry = 0;
    struct ListNode* result = addListsHelper(l1, l2, &carry);

  
    if (carry) {
        struct ListNode* newNode = createNode(carry);
        newNode->next = result;
        result = newNode;
    }

    return result;
}


void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    
    struct ListNode* num1 = createNode(4);
    num1->next = createNode(5);

    struct ListNode* num2 = createNode(3);
    num2->next = createNode(4);
    num2->next->next = createNode(5);

    printf("Number 1: ");
    printList(num1);
    printf("Number 2: ");
    printList(num2);

    struct ListNode* sum = addTwoLists(num1, num2);

    printf("Sum: ");
    printList(sum);

    return 0;
}
