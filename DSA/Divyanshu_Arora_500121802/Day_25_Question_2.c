#include <stdio.h>   
#include <stdlib.h>  
#include <stdbool.h> 
#include <stddef.h>  

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
    if (current == NULL) {
        printf("Empty List\n");
        return;
    }
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

struct ListNode* findIntersection(struct ListNode* head1, struct ListNode* head2) {
    struct ListNode* dummy = createNode(0); 
    struct ListNode* current_intersection = dummy;

    struct ListNode* ptr1 = head1;
    struct ListNode* ptr2 = head2;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->val < ptr2->val) {
            ptr1 = ptr1->next;
        } else if (ptr2->val < ptr1->val) {
            ptr2 = ptr2->next;
        } else { 
            current_intersection->next = createNode(ptr1->val);
            current_intersection = current_intersection->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    struct ListNode* intersection_head = dummy->next;
    free(dummy); 
    return intersection_head;
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
    struct ListNode* head1 = NULL;
    struct ListNode* tail1 = NULL;
    int val;
    char choice;

    printf("First Sorted Linked List\n");
    do {
        printf("Enter a value for the new node (List 1): ");
        if (scanf("%d", &val) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n'); 
            continue;
        }

        struct ListNode* newNode = createNode(val);
        if (head1 == NULL) {
            head1 = newNode;
            tail1 = newNode;
        } else {
            if (val < tail1->val) {
                printf("Warning: Please enter values in increasing order to keep the list sorted.\n");
            }
            tail1->next = newNode;
            tail1 = newNode;
        }

        printf("Would you like to add another node to List 1? (y/n): ");
        while (getchar() != '\n'); 
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');

    struct ListNode* head2 = NULL;
    struct ListNode* tail2 = NULL;

    printf("\nSecond Sorted Linked List \n");
    do {
        printf("Enter a value for the new node (List 2): ");
        if (scanf("%d", &val) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n'); 
            continue;
        }

        struct ListNode* newNode = createNode(val);
        if (head2 == NULL) {
            head2 = newNode;
            tail2 = newNode;
        } else {
            if (val < tail2->val) {
                printf("Warning: Please enter values in increasing order to keep the list sorted.\n");
            }
            tail2->next = newNode;
            tail2 = newNode;
        }

        printf("Would you like to add another node to List 2? (y/n): ");
        while (getchar() != '\n'); 
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nLinkedList1: ");
    printList(head1);
    printf("LinkedList2: ");
    printList(head2);

    struct ListNode* intersectionList = findIntersection(head1, head2);

    printf("Intersection: ");
    printList(intersectionList);

    freeList(head1); 
    freeList(head2); 
    freeList(intersectionList); 

    return 0;
}
