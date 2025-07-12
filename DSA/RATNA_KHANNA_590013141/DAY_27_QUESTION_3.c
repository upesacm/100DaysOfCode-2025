#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insertEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

struct node* removeEveryKth(struct node* head, int k) {
    if (head == NULL || k <= 0) {
        return head;
    }

    if (k == 1) {
        while (head != NULL) {
            struct node* temp = head;
            head = head->next;
            free(temp);
        }
        return NULL;
    }

    struct node* current = head;
    struct node* prev = NULL;
    int count = 1;

    while (current != NULL) {
        if (count % k == 0) {
            struct node* temp = current;
            if (prev != NULL) {
                prev->next = current->next;
            }
            current = current->next;
            free(temp);
            count++;
            continue;
        }
        prev = current;
        current = current->next;
        count++;
    }

    return head;
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int n, val, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }

    printf("Enter k (position interval to remove): ");
    scanf("%d", &k);

    head = removeEveryKth(head, k);

    printf("Final list after removing every %d-th node:\n", k);
    printList(head);

    return 0;
}
