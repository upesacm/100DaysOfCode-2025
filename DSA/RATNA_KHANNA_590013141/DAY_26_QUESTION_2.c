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

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node* temp = l2;
    while (temp != NULL) {
        l1 = insertEnd(l1, temp->data);
        temp = temp->next;
    }
    return l1;
}

void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* prev = current;
        struct Node* temp = current->next;
        while (temp != NULL) {
            if (temp->data == current->data) {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

void sortList(struct Node* head) {
    struct Node* i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

struct Node* createListFromInput(int n) {
    struct Node* head = NULL;
    int val;
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        head = insertEnd(head, val);
    }
    return head;
}

int main() {
    struct Node* L1 = NULL;
    struct Node* L2 = NULL;
    int n1, n2;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);
    L1 = createListFromInput(n1);

    printf("Enter number of elements in List 2: ");
    scanf("%d", &n2);
    L2 = createListFromInput(n2);

    L1 = mergeLists(L1, L2);
    removeDuplicates(L1);
    sortList(L1);

    printf("\nUnion of both lists in sorted order:\n");
    printList(L1);

    return 0;
}
