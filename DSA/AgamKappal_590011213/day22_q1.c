
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

int findMiddle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

int main() {
    struct Node* head = NULL;
    append(&head, 2);
    append(&head, 4);
    append(&head, 6);
    append(&head, 7);
    append(&head, 5);
    append(&head, 1);

    printf("%d\n", findMiddle(head)); // Output: 7

    return 0;
}
