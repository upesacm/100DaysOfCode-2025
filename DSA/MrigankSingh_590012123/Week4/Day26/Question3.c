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

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (!*head) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" → ");
        head = head->next;
    }
    printf("\n");
}

struct Node* sort012(struct Node* head) {
    struct Node zeroD = {0, NULL}, oneD = {0, NULL}, twoD = {0, NULL};
    struct Node *zero = &zeroD, *one = &oneD, *two = &twoD;

    struct Node* current = head;
    while (current) {
        if (current->data == 0) {
            zero->next = current;
            zero = zero->next;
        } else if (current->data == 1) {
            one->next = current;
            one = one->next;
        } else {
            two->next = current;
            two = two->next;
        }
        current = current->next;
    }

    zero->next = oneD.next ? oneD.next : twoD.next;
    one->next = twoD.next;
    two->next = NULL;

    return zeroD.next;
}

int main() {
    int n, val;
    struct Node* head = NULL;

    printf("Enter number of elements in the linked list: ");
    scanf("%d", &n);
    printf("Enter %d elements (only 0s, 1s, and 2s):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        if (val != 0 && val != 1 && val != 2) {
            printf("Invalid input: only 0, 1, and 2 allowed.\n");
            return 1;
        }
        insertEnd(&head, val);
    }

    head = sort012(head);

    printf("Sorted Linked List:\n");
    printList(head);

    return 0;
}
