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
            printf("->");
        temp = temp->next;
    }
    printf("\n");
}

void deleteNafterM(struct node* head, int m, int n) {
    struct node* curr = head;
    struct node* temp;
    int i, j;
    while (curr) {
        for (i = 1; i < m && curr != NULL; i++)
            curr = curr->next;
        if (curr == NULL)
            return;
        temp = curr->next;
        for (j = 1; j <= n && temp != NULL; j++) {
            struct node* del = temp;
            temp = temp->next;
            free(del);
        }
        curr->next = temp;
        curr = temp;
    }
}

int main() {
    int n, m, del;
    struct node* head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    head = createlist(n);
    printf("Enter N (delete): ");
    scanf("%d", &del);

    printf("Enter M (skip): ");
    scanf("%d", &m);
    

    printf("Input:\n");
    display(head);

    deleteNafterM(head, m, del);

    printf("Output:\n");
    display(head);

    return 0;
}
