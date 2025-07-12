#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void removeEveryKthNode(struct Node** head, int k) {
    if (k <= 1 || *head == NULL) {
        struct Node* temp;
        while (*head != NULL) {
            temp = *head;
            *head = (*head)->next;
            free(temp);
        }
        return;
    }

    struct Node* current = *head;
    int count = 1;

    while (current != NULL && current->next != NULL) {
        if (count == k - 1) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            count = 0;
        }
        current = current->next;
        count++;
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, value, i, k;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the node values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    removeEveryKthNode(&head, k);

    printf("Updated Linked list:\n", k);
    printList(head);

    return 0;
}
