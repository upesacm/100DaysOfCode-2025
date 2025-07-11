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

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    while (curr) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* addReversedLists(struct Node* l1, struct Node* l2) {
    struct Node* dummy = newNode(0);
    struct Node* tail = dummy;
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
        tail->next = newNode(sum % 10);
        tail = tail->next;
    }

    return dummy->next;
}

struct Node* removeLeadingZeros(struct Node* head) {
    while (head && head->data == 0)
        head = head->next;
    return head ? head : newNode(0);
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

struct Node* addTwoNumbers(struct Node* num1, struct Node* num2) {
    num1 = reverse(num1);
    num2 = reverse(num2);
    struct Node* result = addReversedLists(num1, num2);

    result = reverse(result);

    return removeLeadingZeros(result);
}

int main() {
    struct Node* num1 = newNode(1);
    num1->next = newNode(9);
    num1->next->next = newNode(0);

    struct Node* num2 = newNode(2);
    num2->next = newNode(5);

    printf("Num1: ");
    printList(num1);
    printf("Num2: ");
    printList(num2);

    struct Node* result = addTwoNumbers(num1, num2);

    printf("Sum: ");
    printList(result);

    return 0;
}
