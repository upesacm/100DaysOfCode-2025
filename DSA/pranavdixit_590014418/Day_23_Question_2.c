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

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (!*head) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

struct Node* removeDuplicates(struct Node* head) {
    struct Node* current = head;
    while (current && current->next) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
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
    int vals1[] = {2, 2, 4, 5};
    for (int i = 0; i < 4; i++) append(&list1, vals1[i]);

    printf("Original List 1: ");
    printList(list1);
    list1 = removeDuplicates(list1);
    printf("After Removing Duplicates: ");
    printList(list1);

    struct Node* list2 = NULL;
    int vals2[] = {2, 2, 2, 2, 2};
    for (int i = 0; i < 5; i++) append(&list2, vals2[i]);

    printf("Original List 2: ");
    printList(list2);
    list2 = removeDuplicates(list2);
    printf("After Removing Duplicates: ");
    printList(list2);

    return 0;
}
