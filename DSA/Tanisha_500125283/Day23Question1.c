//Problem Staement: Given the head of a linked list and the number k, your task is to find the kth node from the 
// end. If k is more than the number of nodes, then the output should be -1. This problem 
// appears frequently in interviews and real-world applications like implementing undo 
// operations, recent history tracking, or buffer management systems. You can solve this by first 
// counting nodes and then traversing again, but try to think of more efficient approaches 
// using the two-pointer technique that requires only one pass. 
// Task: Find the kth node from the end of a linked list using efficient single-pass traversal 
// techniques. 
// Examples Input: LinkedList: 1->2->3->4->5->6->7->8->9, k = 2 
// Output: 8

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int kthelement(struct Node* head, int k) {
    struct Node* first = head;
    struct Node* second = head;
    for (int i = 0; i < k; i++) {
        if (first == NULL) {
            return -1; 
        }
        first = first->next;
    }
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    return second ? second->data : -1;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


int main() {
    
    struct Node* head = createNode(1);
    struct Node* current = head;
    for (int i = 2; i <= 9; i++) {
        current->next = createNode(i);
        current = current->next;
    }

    int k = 2;
    int result = kthelement(head, k);
    printf("%d\n", result); 

    return 0;
}
