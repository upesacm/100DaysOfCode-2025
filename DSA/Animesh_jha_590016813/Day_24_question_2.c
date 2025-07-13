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
void skipMdeleteN(struct Node* head, int m, int n) {
    struct Node* current = head;
    struct Node* temp;

    while (current) {
        for (int i = 1; current && i < m; i++)
            current = current->next;

        if (!current) return;
        temp = current->next;
        for (int i = 0; temp && i < n; i++) {
            struct Node* del = temp;
            temp = temp->next;
            free(del);
        }
        current->next = temp;
        current = temp;
    }
}
void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);

    printf("Original list:\n");
    printList(head);

    int m = 6, n = 1;
    skipMdeleteN(head, m, n);

    printf("Modified list:\n");
    printList(head);

    return 0;
}
