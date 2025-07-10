#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* deleteMiddle(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node *slow = head, *fast = head;
    struct Node *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    prev->next = slow->next;
    free(slow);
    return head;
}

int main() {
    int n, value;
    struct Node *head = NULL, *tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter list values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = deleteMiddle(head);

    printf("List after deleting middle node:\n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
