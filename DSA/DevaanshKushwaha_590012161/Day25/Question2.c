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

ListNode* intersect(ListNode* list1, ListNode* list2) {
    ListNode* intersection = NULL;
    ListNode* tail = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            list1 = list1->next;
        } else if (list1->val > list2->val) {
            list2 = list2->next;
        } else {
            ListNode* newNode = createNode(list1->val);
            if (intersection == NULL) {
                intersection = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
    }
    return intersection;
}

void freeList(ListNode* head) {
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

void printList(ListNode* head) {
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
    printf("Enter sorted values (end with -1): ");
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
    printf("Input for LinkedList1:\n");
    ListNode* list1 = inputList();
    printf("Input for LinkedList2:\n");
    ListNode* list2 = inputList();

    ListNode* intersection = intersect(list1, list2);
    printf("Intersection: ");
    printList(intersection);

    freeList(list1);
    freeList(list2);
    freeList(intersection);
    return 0;
}
