#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

void append(struct Node** head, int data) {
    struct Node* new = createNode(data);
    if (*head == NULL) {
        *head = new;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
    new->prev = temp;
}

struct Node* reverseDLL(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* current = head;

    while (current != NULL) {
        // Swap next and prev
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    return head;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" <-> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }

    printf("Original list:\n");
    printList(head);

    head = reverseDLL(head);

    printf("Reversed list:\n");
    printList(head);

    return 0;
}
