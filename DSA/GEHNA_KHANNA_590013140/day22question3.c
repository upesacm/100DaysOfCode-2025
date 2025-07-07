#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createnode(int newdata) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
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
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    struct node* head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    head = createlist(n);

    printf("The linked list elements are: ");
    display(head);

    return 0;
}
