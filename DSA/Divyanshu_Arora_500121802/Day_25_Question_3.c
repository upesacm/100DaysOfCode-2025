#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    if (current == NULL) {
        printf("Empty List\n");
        return;
    }
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next_node = NULL;

    while (curr != NULL) {
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    return prev;
}

struct ListNode* addTwoNumbers(struct ListNode* num1, struct ListNode* num2) {
    struct ListNode* r_num1 = reverseList(num1);
    struct ListNode* r_num2 = reverseList(num2);

    struct ListNode* dummyHead = createNode(0);
    struct ListNode* currentSum = dummyHead;
    int carry = 0;

    while (r_num1 != NULL || r_num2 != NULL || carry != 0) {
        int sum = carry;
        if (r_num1 != NULL) {
            sum += r_num1->val;
            r_num1 = r_num1->next;
        }
        if (r_num2 != NULL) {
            sum += r_num2->val;
            r_num2 = r_num2->next;
        }

        carry = sum / 10;
        currentSum->next = createNode(sum % 10);
        currentSum = currentSum->next;
    }

    struct ListNode* resultHead = reverseList(dummyHead->next);
    free(dummyHead);

    while (resultHead != NULL && resultHead->val == 0 && resultHead->next != NULL) {
        struct ListNode* temp = resultHead;
        resultHead = resultHead->next;
        free(temp);
    }
    
    if (resultHead == NULL) {
        return createNode(0);
    }

    return resultHead;
}

void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}

int main() {
    struct ListNode* num1_head = NULL;
    struct ListNode* num1_tail = NULL;
    int val;
    char choice;

    printf("First Number (num1) as Linked List \n");
    do {
        printf("Enter a digit for num1 (0-9): ");
        if (scanf("%d", &val) != 1 || val < 0 || val > 9) {
            printf("Invalid input. Please enter a single digit (0-9).\n");
            while (getchar() != '\n');
            continue;
        }

        struct ListNode* newNode = createNode(val);
        if (num1_head == NULL) {
            num1_head = newNode;
            num1_tail = newNode;
        } else {
            num1_tail->next = newNode;
            num1_tail = newNode;
        }

        printf("Add another digit to num1? (y/n): ");
        while (getchar() != '\n');
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');

    struct ListNode* num2_head = NULL;
    struct ListNode* num2_tail = NULL;

    printf("\nSecond Number (num2) as Linked List \n");
    do {
        printf("Enter a digit for num2 (0-9): ");
        if (scanf("%d", &val) != 1 || val < 0 || val > 9) {
            printf("Invalid input. Please enter a single digit (0-9).\n");
            while (getchar() != '\n');
            continue;
        }

        struct ListNode* newNode = createNode(val);
        if (num2_head == NULL) {
            num2_head = newNode;
            num2_tail = newNode;
        } else {
            num2_tail->next = newNode;
            num2_tail = newNode;
        }

        printf("Add another digit to num2? (y/n): ");
        while (getchar() != '\n');
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nnum1: ");
    printList(num1_head);
    printf("num2: ");
    printList(num2_head);

    struct ListNode* sumList = addTwoNumbers(num1_head, num2_head);

    printf("Sum: ");
    printList(sumList);

    freeList(sumList); 
    
    freeList(reverseList(num1_head));
    freeList(reverseList(num2_head));


    return 0;
}
