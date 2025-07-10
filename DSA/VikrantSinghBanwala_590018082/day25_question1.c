#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;      
        current = next;
    }
    return prev;
}
bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true; 
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* secondHalf = reverseList(slow);
    Node* firstHalf = head;
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            return false; 
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true; 
}
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) {
            printf(" -> ");
        }
    }
    printf(" -> NULL\n");
}
int main() {
    Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(1);
    head1->next->next->next = createNode(1);
    head1->next->next->next->next = createNode(2);
    head1->next->next->next->next->next = createNode(1);
    printf("Linked List: ");
    printLinkedList(head1);
    printf("Is Palindrome: %s\n", isPalindrome(head1) ? "true" : "false");
    Node* head2 = createNode(1);
    head2->next = createNode(2);
    head2->next->next = createNode(3);
    head2->next->next->next = createNode(4);
    printf("Linked List: ");
    printLinkedList(head2);
    printf("Is Palindrome: %s\n", isPalindrome(head2) ? "true" : "false");
    return 0;
}