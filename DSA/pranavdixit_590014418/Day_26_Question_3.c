#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int arr[], int n) {
    struct Node* head = NULL, * tail = NULL;
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        if (!head)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next)
            printf(" → ");
        head = head->next;
    }
    printf("\n");
}

struct Node* sortList(struct Node* head) {
    int count[3] = {0};
    struct Node* temp = head;
    while (temp) {
        count[temp->data]++;
        temp = temp->next;
    }

    temp = head;
    int i = 0;
    while (temp) {
        if (count[i] == 0)
            i++;
        else {
            temp->data = i;
            count[i]--;
            temp = temp->next;
        }
    }

    return head;
}

int main() {
    int arr[] = {1, 2, 2, 1, 2, 0, 2, 2};
    struct Node* head = createList(arr, 8);
    head = sortList(head);
    printList(head); 
    return 0;
}
