#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) {
    ListNode* dummyHead = createNode(0);
    ListNode* current = dummyHead;
    int carry = 0;

    while (num1 != NULL || num2 != NULL || carry) {
        int sum = carry;
        if (num1 != NULL) {
            sum += num1->val;
            num1 = num1->next;
        }
        if (num2 != NULL) {
            sum += num2->val;
            num2 = num2->next;
        }
        carry = sum / 10;
        current->next = createNode(sum % 10);
        current = current->next;
    }

    ListNode* result = dummyHead->next;
    free(dummyHead);
    return result;
}

void freeList(ListNode* head) {
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

void printList(ListNode* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    while (head != NULL) {
        printf("%d", head->val);
        head = head->next;
        if (head != NULL) {
            printf("->");
        }
    }
    printf("\n");
}

ListNode* inputList() {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    int value;
    printf("Enter values (end with -1): ");
    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        ListNode* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    printf("Input for num1:\n");
    ListNode* num1 = inputList();
    printf("Input for num2:\n");
    ListNode* num2 = inputList();

    ListNode* sum = addTwoNumbers(num1, num2);
    printf("Sum: ");
    printList(sum);

    freeList(num1);
    freeList(num2);
    freeList(sum);
    return 0;
}
