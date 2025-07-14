#include <stdio.h>
#include <stdlib.h>

// Each person in our line (node in the linked list)
struct ListNode {
    int val;              // The number on their sign
    struct ListNode *next; // Pointer to the next person
};

// Function to remove duplicate numbers
struct ListNode* removeDuplicates(struct ListNode* head) {
    // If the line is empty, nothing to do
    if (head == NULL) {
        return NULL;
    }
    
    // Start with the first person in line
    struct ListNode* current = head;
    
    // While there's still a next person to compare
    while (current->next != NULL) {
        // If current and next person have same number
        if (current->val == current->next->val) {
            // Remember the duplicate person
            struct ListNode* duplicate = current->next;
            // Make current point to the person after the duplicate
            current->next = current->next->next;
            // Free the duplicate's memory (they leave the line)
            free(duplicate);
        } else {
            // Numbers are different, move to next person
            current = current->next;
        }
    }
    
    // Return the cleaned-up line
    return head;
}

// Helper to create a new person in line
struct ListNode* newNode(int val) {
    struct ListNode* person = (struct ListNode*)malloc(sizeof(struct ListNode));
    person->val = val;
    person->next = NULL;
    return person;
}

// Helper to print the line of people
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

// Main function to test our solution
int main() {
    // Create first test line: 2 -> 2 -> 4 -> 5
    struct ListNode* line1 = newNode(2);
    line1->next = newNode(2);
    line1->next->next = newNode(4);
    line1->next->next->next = newNode(5);
    
    printf("Original line: ");
    printList(line1);
    
    line1 = removeDuplicates(line1);
    printf("After removing duplicates: ");
    printList(line1);
    
    // Create second test line: all 2's
    struct ListNode* line2 = newNode(2);
    line2->next = newNode(2);
    line2->next->next = newNode(2);
    line2->next->next->next = newNode(2);
    line2->next->next->next->next = newNode(2);
    
    printf("\nOriginal line: ");
    printList(line2);
    
    line2 = removeDuplicates(line2);
    printf("After removing duplicates: ");
    printList(line2);
    
    return 0;
}
