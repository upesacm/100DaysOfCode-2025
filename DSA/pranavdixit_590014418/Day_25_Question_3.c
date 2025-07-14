#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void append(struct Node** head, int val) {
    struct Node* temp = newNode(val);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct Node* curr = *head;
    while (curr->next)
        curr = curr->next;
    curr->next = temp;
}

struct Node* addNumbers(struct Node* l1, struct Node* l2) {
    struct Node* dummy = newNode(0);
    struct Node* temp = dummy;
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
        temp->next = newNode(sum % 10);
        temp = temp->next;
    }

    return dummy->next;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;

    append(&num1, 4);
    append(&num1, 5);

    append(&num2, 3);
    append(&num2, 4);
    append(&num2, 5);

    printf("Number 1: ");
    printList(num1);

    printf("Number 2: ");
    printList(num2);

    struct Node* result = addNumbers(num1, num2);

    printf("Sum: ");
    printList(result);

    return 0;
}
