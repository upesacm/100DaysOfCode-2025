#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Node* insertEnd(struct Node* head, int data) {
    if (!head) return newNode(data);
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode(data);
    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* addLists(struct Node* l1, struct Node* l2) {
    struct Node* dummy = newNode(0);
    struct Node* curr = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->data; l1 = l1->next; }
        if (l2) { sum += l2->data; l2 = l2->next; }

        carry = sum / 10;
        curr->next = newNode(sum % 10);
        curr = curr->next;
    }

    return dummy->next;
}

int main() {
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;


    num1 = insertEnd(num1, 4);
    num1 = insertEnd(num1, 5);


    num2 = insertEnd(num2, 3);
    num2 = insertEnd(num2, 4);
    num2 = insertEnd(num2, 5);

    struct Node* result = addLists(num1, num2);

    printf("Sum: ");
    printList(result);

    return 0;
}
