#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter sorted values:\n");
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

    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    printf("List after removing duplicates:\n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
