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

int getLength(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* swapKth(struct Node* head, int k) {
    int n = getLength(head);
    if (k > n) return head;
    if (2 * k - 1 == n) return head; 

    struct Node* prevX = NULL, *currX = head;
    for (int i = 1; i < k; i++) {
        prevX = currX;
        currX = currX->next;
    }

    struct Node* prevY = NULL, *currY = head;
    for (int i = 1; i < n - k + 1; i++) {
        prevY = currY;
        currY = currY->next;
    }

    if (prevX) prevX->next = currY;
    else head = currY;

    if (prevY) prevY->next = currX;
    else head = currX;

    struct Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    int k = 1;

    printf("Original List: ");
    printList(head);

    head = swapKth(head, k);

    printf("Modified List: ");
    printList(head);

    return 0;
}
