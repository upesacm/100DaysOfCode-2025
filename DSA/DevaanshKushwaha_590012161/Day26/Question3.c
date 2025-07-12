#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Insert at end
struct Node* insertEnd(struct Node* head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (!head) return newNode;
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Sort the list
struct Node* sortList(struct Node* head) {
    struct Node zeroDummy = {0, NULL}, oneDummy = {0, NULL}, twoDummy = {0, NULL};
    struct Node *zero = &zeroDummy, *one = &oneDummy, *two = &twoDummy;

    while (head) {
        if (head->data == 0) {
            zero->next = head;
            zero = zero->next;
        } else if (head->data == 1) {
            one->next = head;
            one = one->next;
        } else {
            two->next = head;
            two = two->next;
        }
        head = head->next;
    }

    // Connect lists
    zero->next = oneDummy.next ? oneDummy.next : twoDummy.next;
    one->next = twoDummy.next;
    two->next = NULL;

    return zeroDummy.next;
}

// Print linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter values (only 0s, 1s, and 2s): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }

    head = sortList(head);
    printf("Sorted List: ");
    printList(head);

    return 0;
}
