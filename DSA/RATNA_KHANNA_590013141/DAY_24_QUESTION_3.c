#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
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
        if (head == NULL)
            head = temp;
        else
            current->next = temp;
        current = temp;
    }
    return head;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

struct node* deleteAtPosition(struct node* head, int x) {
    if (head == NULL)
        return head;
    if (x == 1) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct node* curr = head;
    for (int i = 1; i < x - 1 && curr != NULL; i++)
        curr = curr->next;
    if (curr == NULL || curr->next == NULL)
        return head;
    struct node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    return head;
}

int main() {
    int n, x;
    struct node* head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    head = createlist(n);

    printf("Enter position to delete: ");
    scanf("%d", &x);

    printf("Input:\n");
    display(head);

    head = deleteAtPosition(head, x);

    printf("Output:\n");
    display(head);

    return 0;
}
