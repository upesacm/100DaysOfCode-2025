#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void deleteN(struct Node* head, int m, int n) {
    struct Node* current = head;
    struct Node* temp;
    int count;

    while (current != NULL) {
   
        for (count = 1; count < m && current != NULL; count++)
            current = current->next;

        if (current == NULL)
            return;

        temp = current->next;
        for (count = 1; count <= n && temp != NULL; count++) {
            struct Node* del = temp;
            temp = temp->next;
            free(del);
        }

        current->next = temp;
        current = temp;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int n, m, total, value;

    printf("Enter total number of nodes: ");
    scanf("%d", &total);

    printf("Enter %d values:\n", total);
    for (int i = 0; i < total; i++) {
        scanf("%d", &value);
        newNode = createNode(value);
        if (head == NULL)
            head = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter number of nodes to skip: ");
    scanf("%d", &m);
    printf("Enter number of nodes to delete: ");
    scanf("%d", &n);

    printf("Original List:\n");
    printList(head);

    deleteN(head, m, n);

    printf("Modified List:\n");
    printList(head);

    return 0;
}
