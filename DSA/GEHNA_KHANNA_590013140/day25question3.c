#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *next;
    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (!head) return temp;
    struct Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = temp;
    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *num1 = NULL, *num2 = NULL, *sum = NULL;
    int n1, n2, x;

    printf("Enter number of digits in first number: ");
    scanf("%d", &n1);
    printf("Enter %d digits : ", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &x);
        num1 = insertEnd(num1, x);
    }

    printf("Enter number of digits in second number: ");
    scanf("%d", &n2);
    printf("Enter %d digits : ", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &x);
        num2 = insertEnd(num2, x);
    }

    num1 = reverse(num1);
    num2 = reverse(num2);

    struct Node *temp1 = num1, *temp2 = num2;
    int carry = 0;
    while (temp1 || temp2 || carry) {
        int s = carry;
        if (temp1) {
            s += temp1->data;
            temp1 = temp1->next;
        }
        if (temp2) {
            s += temp2->data;
            temp2 = temp2->next;
        }
        sum = insertEnd(sum, s % 10);
        carry = s / 10;
    }

    sum = reverse(sum);
    printf("Sum: ");
    printList(sum);

    return 0;
}
