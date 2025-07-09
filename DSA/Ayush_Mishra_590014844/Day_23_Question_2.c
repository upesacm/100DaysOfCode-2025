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

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    while (current && current->next) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, val;

    printf("Enter number of nodes (sorted list): ");
    scanf("%d", &n);
    printf("Enter %d sorted node values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }

    removeDuplicates(head);
    printf("List after removing duplicates:\n");
    printList(head);

    return 0;
}
