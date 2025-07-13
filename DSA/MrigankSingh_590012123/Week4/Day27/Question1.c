#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} DoublyLinkedList;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void initList(DoublyLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void insertAtEnd(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
    list->size++;
}

bool delete_position(DoublyLinkedList* list, int position) {
    if (position <= 0 || position > list->size) {
        printf("Invalid position.\n");
        return false;
    }
    Node* current = list->head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;
    }
    free(current);
    list->size--;
    return true;
}

void printList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" <--> ");
        }
        current = current->next;
    }
    printf("\n");
}

void freeList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int main() {
    DoublyLinkedList list;
    initList(&list);

    int size, position, data;

    printf("Enter the size of the linked list (must be > 0): ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Invalid size. Size must be greater than 0.\n");
        return 1;
    }

    printf("Enter the elements of the linked list: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &data);
        insertAtEnd(&list, data);
    }

    printf("Original list: ");
    printList(&list);

    printf("Enter the position to delete (1-based index): ");
    scanf("%d", &position);

    if (delete_position(&list, position)) {
        printf("List after deletion: ");
        printList(&list);
    }

    freeList(&list);

    return 0;
}