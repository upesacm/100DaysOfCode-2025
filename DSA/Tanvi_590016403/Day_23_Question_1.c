#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Utility function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Utility function to print the linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}

// 1. Kth node from the end using two-pointer approach
int kthFromEnd(struct Node* head, int k) {
    struct Node *first = head, *second = head;
    for (int i = 0; i < k; i++) {
        if (second == NULL) return -1;
        second = second->next;
    }
    while (second) {
        first = first->next;
        second = second->next;
    }
    return first ? first->data : -1;
}

// 2. Remove duplicates from a sorted linked list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    while (current && current->next) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

// 3. Delete middle node (delete second middle if even)
struct Node* deleteMiddle(struct Node* head) {
    if (!head || !head->next) {
        free(head);
        return NULL;
    }

    struct Node *slow = head, *fast = head;
    struct Node *prev = NULL;

    while (fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    prev->next = slow->next;
    free(slow);

    return head;
}

// Utility to append to the end of the list
void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Main function to test all features
int main() {
    // Example 1: Kth from end
    struct Node* list1 = NULL;
    int arr1[] = {1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < 9; i++) append(&list1, arr1[i]);

    printf("Original List 1: ");
    printList(list1);
    int k = 2;
    printf("Kth (%d) node from end: %d\n\n", k, kthFromEnd(list1, k));

    // Example 2: Remove duplicates
    struct Node* list2 = NULL;
    int arr2[] = {2,2,2,4,4,5};
    for (int i = 0; i < 6; i++) append(&list2, arr2[i]);

    printf("Original List 2: ");
    printList(list2);
    removeDuplicates(list2);
    printf("After Removing Duplicates: ");
    printList(list2);
    printf("\n");

    // Example 3: Delete middle node
    struct Node* list3 = NULL;
    int arr3[] = {2,4,6,7,5,1};
    for (int i = 0; i < 6; i++) append(&list3, arr3[i]);

    printf("Original List 3: ");
    printList(list3);
    list3 = deleteMiddle(list3);
    printf("After Deleting Middle Node: ");
    printList(list3);

    return 0;
}
