#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* deleteMiddle(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        free(head);
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

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

struct Node* createExampleList() {
    struct Node* head = newNode(2);
    head->next = newNode(4);
    head->next->next = newNode(6);
    head->next->next->next = newNode(7);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(1);
    return head;
}

int main() {
    struct Node* head = createExampleList();

    printf("Original List:\n");
    printList(head);

    head = deleteMiddle(head);

    printf("After Deleting Middle:\n");
    printList(head);

    return 0;
}
