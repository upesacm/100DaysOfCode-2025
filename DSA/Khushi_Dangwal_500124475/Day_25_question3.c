#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

// Function to remove leading zeros
struct ListNode* removeLeadingZeros(struct ListNode* head) {
    while (head != NULL && head->val == 0 && head->next != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

// Function to add two numbers represented as linked lists
struct ListNode* addTwoNumbers(struct ListNode* num1, struct ListNode* num2) {
    // Reverse both lists to start adding from least significant digit
    num1 = reverseList(num1);
    num2 = reverseList(num2);
    
    struct ListNode* result = NULL;
    struct ListNode** tail = &result;
    int carry = 0;
    
    // Add digits one by one
    while (num1 != NULL || num2 != NULL || carry != 0) {
        int sum = carry;
        
        if (num1 != NULL) {
            sum += num1->val;
            num1 = num1->next;
        }
        
        if (num2 != NULL) {
            sum += num2->val;
            num2 = num2->next;
        }
        
        carry = sum / 10;
        *tail = newNode(sum % 10);
        tail = &((*tail)->next);
    }
    
    // Reverse the result to get the correct order
    result = reverseList(result);
    
    // Remove leading zeros
    result = removeLeadingZeros(result);
    
    // If all digits were zero, return a single zero
    if (result == NULL) {
        return newNode(0);
    }
    
    return result;
}

// Function to print a linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) {
            printf(" -> ");
        }
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Test case 1: 45 + 345 = 390
    struct ListNode* num1 = newNode(4);
    num1->next = newNode(5);
    
    struct ListNode* num2 = newNode(3);
    num2->next = newNode(4);
    num2->next->next = newNode(5);
    
    printf("Number 1: ");
    printList(num1);
    printf("Number 2: ");
    printList(num2);
    
    struct ListNode* sum = addTwoNumbers(num1, num2);
    printf("Sum: ");
    printList(sum);
    
    // Test case 2: 0063 + 07 = 70
    struct ListNode* num3 = newNode(0);
    num3->next = newNode(0);
    num3->next->next = newNode(6);
    num3->next->next->next = newNode(3);
    
    struct ListNode* num4 = newNode(0);
    num4->next = newNode(7);
    
    printf("\nNumber 3: ");
    printList(num3);
    printf("Number 4: ");
    printList(num4);
    
    struct ListNode* sum2 = addTwoNumbers(num3, num4);
    printf("Sum: ");
    printList(sum2);
    
    return 0;
}
