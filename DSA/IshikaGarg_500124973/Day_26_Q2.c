#include <stdio.h>
#include <stdlib.h>

#define MAX 10001  // Assuming data values are between 0 and 10000

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* temp = newNode(data);
    if (!head)
        return temp;
    
    struct Node* curr = head;
    while (curr->next)
        curr = curr->next;
    
    curr->next = temp;
    return head;
}

// Utility function to print list
void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Function to make union of two lists
struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    int seen[MAX] = {0}; // To track unique elements
    struct Node* temp;

    // Traverse first list
    temp = head1;
    while (temp) {
        seen[temp->data] = 1;
        temp = temp->next;
    }

    // Traverse second list
    temp = head2;
    while (temp) {
        seen[temp->data] = 1;
        temp = temp->next;
    }

    // Create new list with sorted unique elements
    struct Node* unionList = NULL;
    for (int i = 0; i < MAX; i++) {
        if (seen[i]) {
            unionList = insertEnd(unionList, i);
        }
    }

    return unionList;
}

// Driver code
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Example 1
    head1 = insertEnd(head1, 9);
    head1 = insertEnd(head1, 6);
    head1 = insertEnd(head1, 4);
    head1 = insertEnd(head1, 2);
    head1 = insertEnd(head1, 3);
    head1 = insertEnd(head1, 8);

    head2 = insertEnd(head2, 1);
    head2 = insertEnd(head2, 2);
    head2 = insertEnd(head2, 8);
    head2 = insertEnd(head2, 6);
    head2 = insertEnd(head2, 2);

    printf("List 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);

    struct Node* unionList = makeUnion(head1, head2);

    printf("Union (sorted, distinct): ");
    printList(unionList);

    return 0;
}
