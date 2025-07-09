#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createnode(int newdata) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = newdata;
    newnode->next = NULL;
    return newnode;
}

struct node* createlist(int n) {
    struct node *head = NULL, *temp = NULL, *current = NULL;
    int data;
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        temp = createnode(data);
        if (head == NULL) {
            head = temp;
        } else {
            current->next = temp;
        }
        current = temp;
    }
    return head;
}

void display(struct node* head) {
    if (head == NULL) {
        printf("head: NULL\n");
        return;
    }

    struct node* temp = head;

    if (head->next != NULL) {
        printf("head: ");
    }

    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        else
            printf(" -> NULL");
        temp = temp->next;
    }
    printf("\n");
}

struct node* reverse(struct node* head) {
    struct node* curr = head;
    struct node* prev = NULL;
    struct node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    int n;
    struct node* head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    head = createlist(n);

    printf("Input:\n");
    display(head);

    head = reverse(head);

    printf("Output:\n");
    display(head);

    return 0;
}
