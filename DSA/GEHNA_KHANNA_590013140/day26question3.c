#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create(int data) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    return new;
}

void append(struct Node** head, int data) {
    struct Node* new = create(data);
    if (*head == NULL) {
        *head = new;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = new;
}

void sortList(struct Node* head) {
    int count0 = 0, count1 = 0, count2 = 0;

    struct Node* temp = head;

    while (temp) {
        if (temp->data == 0) count0++;
        else if (temp->data == 1) count1++;
        else count2++;
        temp = temp->next;
    }

    temp = head;

    while (count0--) {
        temp->data = 0;
        temp = temp->next;
    }
    while (count1--) {
        temp->data = 1;
        temp = temp->next;
    }
    while (count2--) {
        temp->data = 2;
        temp = temp->next;
    }
}

void print(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    struct Node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values (only 0, 1, or 2):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }

    sortList(head);
    printf("Sorted List:\n");
    print(head);

    return 0;
}
