#include <stdio.h>   // For printf
#include <stdlib.h>  // For malloc and free
#include <stdbool.h> // For bool type
#include <stddef.h>  // For NULL

// Definition for singly-linked list node.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next_node = NULL; 

    while (curr != NULL) {
        next_node = curr->next; 
        curr->next = prev;      
        prev = curr;            
        curr = next_node;       
    }
    return prev; 
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true; 
    }

    struct ListNode* mid = head;      
    struct ListNode* next_ptr = head; 


    while (next_ptr->next != NULL && next_ptr->next->next != NULL) {
        mid = mid->next;
        next_ptr = next_ptr->next->next;
    }

    struct ListNode* second_half_start = mid->next;
    mid->next = NULL; 
    struct ListNode* reversed_second_half = reverseList(second_half_start);

    struct ListNode* first_half_ptr = head;
    struct ListNode* second_half_ptr = reversed_second_half;
    bool is_pal = true;

    while (first_half_ptr != NULL && second_half_ptr != NULL) {
        if (first_half_ptr->val != second_half_ptr->val) {
            is_pal = false; 
            break;
        }
        first_half_ptr = first_half_ptr->next;
        second_half_ptr = second_half_ptr->next;
    }

    struct ListNode* original_second_half = reverseList(reversed_second_half);
    mid->next = original_second_half;

    return is_pal;
}


struct ListNode* left_ptr; 

bool checkRecursive(struct ListNode* right) {
    if (right == NULL) {
        return true;
    }

    if (!checkRecursive(right->next)) {
        return false;
    }
    if (left_ptr->val != right->val) {
        return false; 
    }

    left_ptr = left_ptr->next;
    return true; 
}

bool isPalindromeRecursive(struct ListNode* head) {
    left_ptr = head; 
    return checkRecursive(head); 
}

void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}

int main() {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    int val;
    char choice;

    do {
        printf("Enter a value for the new node: ");
        if (scanf("%d", &val) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        struct ListNode* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        printf("Would you like to add another node? (y/n): ");
        while (getchar() != '\n'); // Clear input buffer
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nYour created List: ");
    printList(head);
    printf("Is palindrome? : %s\n", isPalindromeRecursive(head) ? "true" : "false");
    freeList(head); 

    return 0;
}
