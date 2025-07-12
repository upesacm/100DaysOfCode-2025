#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
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

struct Node* removeDuplicates(struct Node* head) {
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* duplicate = current->next;
            current->next = duplicate->next;
            free(duplicate);
        } else {
            current = current->next;
        }
    }
    return head;
}

struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    struct Node* unionList = NULL;
    struct Node* temp = head1;

    while (temp != NULL) {
        insertEnd(&unionList, temp->data);
        temp = temp->next;
    }

    temp = head2;
    while (temp != NULL) {
        insertEnd(&unionList, temp->data);
        temp = temp->next;
    }

    sortList(unionList);

    unionList = removeDuplicates(unionList);

    return unionList;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int n, value, i;

    printf("Enter number of elements for first linked list: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head1, value);
    }

    printf("Enter number of elements for second linked list: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head2, value);
    }

    struct Node* result = makeUnion(head1, head2);

    printf("Union of the two linked lists:\n");
    printList(result);

    return 0;
}
