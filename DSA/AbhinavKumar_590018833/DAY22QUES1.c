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

int findMiddle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

struct Node* buildList(int arr[], int size) {
    if (size == 0) return NULL;

    struct Node* head = createNode(arr[0]);
    struct Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }

    return head;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    struct Node* list1 = buildList(arr1, 5);
    printf("Middle of list1: %d\n", findMiddle(list1));  

    int arr2[] = {2, 4, 6, 7, 5, 1};
    struct Node* list2 = buildList(arr2, 6);
    printf("Middle of list2: %d\n", findMiddle(list2)); 

    return 0;
}
