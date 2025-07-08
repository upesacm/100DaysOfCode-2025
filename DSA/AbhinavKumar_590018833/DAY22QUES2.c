// 2. Frequency in a Linked List
// A problem that demonstrates linked list traversal and counting techniques, teaching how to
// search and count occurrences of specific elements.
// Given a singly linked list and a key, count the number of occurrences of the given key in the
// linked list. This operation is fundamental in data analysis and frequency counting
// applications where you need to determine how often specific values appear in sequential
// data structures. The challenge involves understanding how to traverse the entire list while
// maintaining an accurate count of matches.
// This introduces sequential search algorithms and frequency analysis techniques that are
// crucial for data processing and statistical analysis of linked data structures.
// Your task: Count occurrences of a specific key in a linked list using efficient traversal and
// counting methods.
// Examples
// Input:
// Linked List: 1->2->1->2->1->3->1, key = 1
// Output:
// 4
// Input:
// Linked List: 1->2->1->2->1, key = 3
// Output:
// 0
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* buildList(int arr[], int size) {
    if (size == 0) return NULL;

    struct Node* head = createNode(arr[0]);
    struct Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }

    return head;
}

int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }

    return count;
}

int main() {
    int arr1[] = {1, 2, 1, 2, 1, 3, 1};
    struct Node* list1 = buildList(arr1, 7);
    printf("Occurrences of 1: %d\n", countOccurrences(list1, 1)); 

    int arr2[] = {1, 2, 1, 2, 1};
    struct Node* list2 = buildList(arr2, 5);
    printf("Occurrences of 3: %d\n", countOccurrences(list2, 3));  

    return 0;
}
