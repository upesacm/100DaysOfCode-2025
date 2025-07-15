#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* removeEveryKthNode(struct Node* head, int k) {
    if (k <= 1 || head == NULL)
        return NULL;

    struct Node* current = head;
    int count = 1;

    while (current != NULL && current->next != NULL) {
        if ((count + 1) % k == 0) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            count++;
        } else {
            current = current->next;
            count++;
        }
    }

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
    struct Node* head = NULL;

    for (int i = 1; i <= 10; i++)
        head = insertEnd(head, i);

    int k = 3;
    head = removeEveryKthNode(head, k);

    printList(head);

    return 0;
}
