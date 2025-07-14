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

struct Node* appendNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;
    
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* deleteNafterM(struct Node* head, int m, int n) {
    struct Node* current = head;
    struct Node* temp;
    int i;

    while (current != NULL) {
        for (i = 1; i < m && current != NULL; i++) {
            current = current->next;
        }

        if (current == NULL)
            break;

        temp = current->next;
        for (i = 0; i < n && temp != NULL; i++) {
            struct Node* nodeToDelete = temp;
            temp = temp->next;
            free(nodeToDelete);
        }

        current->next = temp;
        current = temp;
    }

    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, m, total, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &total);

    printf("Enter %d node values:\n", total);
    for (int i = 0; i < total; i++) {
        scanf("%d", &value);
        head = appendNode(head, value);
    }

    printf("Enter number of nodes to skip (m): ");
    scanf("%d", &m);

    printf("Enter number of nodes to delete (n): ");
    scanf("%d", &n);

    printf("Original List:\n");
    printList(head);

    head = deleteNafterM(head, m, n);

    printf("List after deleting %d nodes after every %d nodes:\n", n, m);
    printList(head);

    return 0;
}
