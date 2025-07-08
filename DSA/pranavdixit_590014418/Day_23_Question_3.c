#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}

void append(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    if (!*head) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

struct Node* deleteMiddle(struct Node* head) {
    if (!head || !head->next) return NULL;

    struct Node *slow = head, *fast = head, *prev = NULL;
    while (fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    prev->next = slow->next;
    free(slow);
    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* list1 = NULL;
    int vals1[] = {1,2,3,4,5};
    for (int i = 0; i < 5; i++) append(&list1, vals1[i]);

    printf("Original List 1: ");
    printList(list1);
    list1 = deleteMiddle(list1);
    printf("After Deleting Middle: ");
    printList(list1);

    struct Node* list2 = NULL;
    int vals2[] = {2,4,6,7,5,1};
    for (int i = 0; i < 6; i++) append(&list2, vals2[i]);

    printf("Original List 2: ");
    printList(list2);
    list2 = deleteMiddle(list2);
    printf("After Deleting Middle: ");
    printList(list2);

    return 0;
}
