#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    while (current) {
        struct Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

bool isPalindrome(struct Node* head) {
    if (!head || !head->next)
        return true;

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* secondHalf = reverse(slow->next);
    struct Node* firstHalf = head;
    struct Node* temp = secondHalf;

    while (temp) {
        if (firstHalf->data != temp->data)
            return false;
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    return true;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(1);
    head->next->next->next = newNode(1);
    head->next->next->next->next = newNode(2);
    head->next->next->next->next->next = newNode(1);

    printf("Input List: ");
    printList(head);

    if (isPalindrome(head))
        printf("Output: true\n");
    else
        printf("Output: false\n");

    return 0;
}
