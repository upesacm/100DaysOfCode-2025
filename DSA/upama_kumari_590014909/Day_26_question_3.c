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

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void sort012(struct Node** head_ref) {
    struct Node *zeroD = newNode(0); 
    struct Node *oneD = newNode(0);  
    struct Node *twoD = newNode(0);  

    struct Node *zero = zeroD, *one = oneD, *two = twoD;
    struct Node *curr = *head_ref;

    while (curr != NULL) {
        if (curr->data == 0) {
            zero->next = curr;
            zero = zero->next;
        } else if (curr->data == 1) {
            one->next = curr;
            one = one->next;
        } else {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }

    zero->next = (oneD->next) ? oneD->next : twoD->next;
    one->next = twoD->next;
    two->next = NULL;

    *head_ref = zeroD->next;

    free(zeroD);
    free(oneD);
    free(twoD);
}

int main() {
    struct Node* head = newNode(2);
    head->next = newNode(2);
    head->next->next = newNode(0);
    head->next->next->next = newNode(1);

    printf("Original List:\n");
    printList(head);

    sort012(&head);

    printf("Sorted List:\n");
    printList(head);

    return 0;
}
