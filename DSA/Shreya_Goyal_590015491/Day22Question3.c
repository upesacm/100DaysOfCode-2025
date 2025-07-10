#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int n, i, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Number of nodes to be added: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        newNode->val = value;
        newNode->next = NULL;

        if (head == NULL) {
             head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    printf("Linked list: ");
    printList(head);

    return 0;
}
