#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* buildLinkedList(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* head = createNode(arr[0]);
    struct Node* current = head;

    for (int i = 1; i < n; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }

    return head;
}

struct Node* removeEveryKthNode(struct Node* head, int k) {
    if (k <= 0 || !head) return head;
    if (k == 1) {
        struct Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            free(temp);
        }
        return NULL;
    }

    int count = 1;
    struct Node* curr = head;
    struct Node* prev = NULL;

    while (curr) {
        if (count % k == 0) {
            // Delete curr
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
        count++;
    }
    return head;
}

void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d", temp->data);
        if (temp->next) printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int arr1[] = {1,2,3,4,5,6,7,8};
    int k1 = 2;
    struct Node* list1 = buildLinkedList(arr1, sizeof(arr1)/sizeof(arr1[0]));
    printf("Original List:\n");
    printLinkedList(list1);
    list1 = removeEveryKthNode(list1, k1);
    printf("After removing every %d-th node:\n", k1);
    printLinkedList(list1);

    printf("\n");

    int arr2[] = {1,2,3,4,5,6,7,8,9,10};
    int k2 = 3;
    struct Node* list2 = buildLinkedList(arr2, sizeof(arr2)/sizeof(arr2[0]));
    printf("Original List:\n");
    printLinkedList(list2);
    list2 = removeEveryKthNode(list2, k2);
    printf("After removing every %d-th node:\n", k2);
    printLinkedList(list2);

    return 0;
}
