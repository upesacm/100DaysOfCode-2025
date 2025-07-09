#include <stdio.h>
#include <stdlib.h>

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
    struct Node* curr = *headRef;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

struct Node* deleteMiddle(struct Node* head) {
    if (!head || !head->next) {
        free(head);
        return NULL;
    }

    struct Node *slow = head, *fast = head, *prev = NULL;

    while (fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // Delete the middle node
    prev->next = slow->next;
    free(slow);

    return head;
}

int main() {
    struct Node* head = NULL;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) append(&head, arr[i]);

    printf("Original list:\n");
    printList(head);

    head = deleteMiddle(head);

    printf("List after deleting middle node:\n");
    printList(head);

    return 0;
}
