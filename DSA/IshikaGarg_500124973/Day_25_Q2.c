#include <stdio.h>
#include <stdlib.h>

// Node structure
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end of result list
void insertAtEnd(struct ListNode** head, int val) {
    struct ListNode* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct ListNode* temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to find intersection of two sorted linked lists
struct ListNode* getIntersection(struct ListNode* head1, struct ListNode* head2) {
    struct ListNode* result = NULL;

    while (head1 && head2) {
        if (head1->val < head2->val) {
            head1 = head1->next;
        } else if (head1->val > head2->val) {
            head2 = head2->next;
        } else {
            insertAtEnd(&result, head1->val);
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return result;
}

// Function to print a list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Sample test driver
int main() {
    // LinkedList1 = 1->2->3->4->6
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(3);
    list1->next->next->next = createNode(4);
    list1->next->next->next->next = createNode(6);

    // LinkedList2 = 2->4->6->8
    struct ListNode* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);
    list2->next->next->next = createNode(8);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    struct ListNode* intersection = getIntersection(list1, list2);
    printf("Intersection: ");
    printList(intersection);

    return 0;
}
