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

struct Node* deleteMiddle(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    struct Node *slow = head, *fast = head, *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    prev->next = slow->next;
    free(slow);

    return head;
}

int main() {
    int n, val, i;
    struct Node *head = NULL, *temp = NULL, *tail = NULL;

    printf("Number of nodes you want to enter: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);

        temp = createNode(val);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }


    head = deleteMiddle(head);

    printf("\nUpdated Linked List:\n");
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        printList(head);
    }

    return 0;
}
