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
    struct Node* temp = newNode(data);
    if (!head)
        return temp;

    struct Node* curr = head;
    while (curr->next)
        curr = curr->next;

    curr->next = temp;
    return head;
}


void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}


struct Node* sortList(struct Node* head) {
    if (!head || !head->next)
        return head;

   
    struct Node *zeroHead = NULL, *zeroTail = NULL;
    struct Node *oneHead = NULL, *oneTail = NULL;
    struct Node *twoHead = NULL, *twoTail = NULL;

    struct Node* curr = head;

    while (curr) {
        if (curr->data == 0) {
            if (!zeroHead)
                zeroHead = zeroTail = curr;
            else {
                zeroTail->next = curr;
                zeroTail = curr;
            }
        } else if (curr->data == 1) {
            if (!oneHead)
                oneHead = oneTail = curr;
            else {
                oneTail->next = curr;
                oneTail = curr;
            }
        } else {
            if (!twoHead)
                twoHead = twoTail = curr;
            else {
                twoTail->next = curr;
                twoTail = curr;
            }
        }
        curr = curr->next;
    }

    
    if (zeroTail) zeroTail->next = oneHead ? oneHead : twoHead;
    if (oneTail) oneTail->next = twoHead;
    if (twoTail) twoTail->next = NULL;

    // Set new head
    if (zeroHead)
        return zeroHead;
    else if (oneHead)
        return oneHead;
    else
        return twoHead;
}

int main() {
    struct Node* head = NULL;

    
    int arr[] = {1, 2, 2, 1, 2, 0, 2, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        head = insertEnd(head, arr[i]);

    printf("Original List:\n");
    printList(head);

    head = sortList(head);

    printf("Sorted List:\n");
    printList(head);

    return 0;
}
