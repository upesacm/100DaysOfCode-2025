#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void append(struct Node** headRef, int data) {
    struct Node* temp = newNode(data);
    if (*headRef == NULL) {
        *headRef = temp;
        return;
    }
    struct Node* current = *headRef;
    while (current->next != NULL)
        current = current->next;
    current->next = temp;
}

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool compareLists(struct Node* head1, struct Node* head2) {
    while (head1 && head2) {
        if (head1->data != head2->data)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

bool isPalindrome(struct Node* head) {
    if (!head || !head->next)
        return true;

    struct Node *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* secondHalf = reverse(slow->next);
    bool result = compareLists(head, secondHalf);
    slow->next = reverse(secondHalf);  
    return result;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


int main() {
    struct Node* head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 1);
    append(&head, 1);
    append(&head, 2);
    append(&head, 1);

    if (isPalindrome(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
