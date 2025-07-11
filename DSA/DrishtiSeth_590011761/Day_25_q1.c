
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    if (head == NULL || head->next == NULL)
        return true;

    Node *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* secondHalf = reverseList(slow->next);
    Node* firstHalf = head;

    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(1);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(2);
    head->next->next->next->next->next = createNode(1);

    if (isPalindrome(head))
        printf("true\n");
    else
        printf("false\n");

    freeList(head);
    return 0;
}
