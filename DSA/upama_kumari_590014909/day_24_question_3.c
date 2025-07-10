#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Node* deleteNode(struct Node* head, int x) {
    if (head == NULL) return NULL;

    if (x == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    for (int i = 1; i < x - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) return head;

    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = newNode(1);
    head->next = newNode(3);
    head->next->next = newNode(4);

    printf("Original List:\n");
    printList(head);

    int x = 3;
    head = deleteNode(head, x);

    printf("Modified List:\n");
    printList(head);

    return 0;
}
