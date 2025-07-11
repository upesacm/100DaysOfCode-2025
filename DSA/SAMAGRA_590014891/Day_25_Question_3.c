#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void append(struct Node** headRef, int data) {
    struct Node* temp = newNode(data);
    if (*headRef == NULL) {
        *headRef = temp;
        return;
    }
    struct Node* current = *headRef;
    while (current->next != NULL)
        current = current->next;
    current->next = temp;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}

struct Node* addLists(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    struct Node** tail = &result;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        *tail = newNode(sum % 10);
        tail = &((*tail)->next);
    }
    return result;
}

int main() {
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;

    append(&num1, 4);
    append(&num1, 5);

    append(&num2, 3);
    append(&num2, 4);
    append(&num2, 5);

    struct Node* sum = addLists(num1, num2);

    printList(sum);

    return 0;
}
