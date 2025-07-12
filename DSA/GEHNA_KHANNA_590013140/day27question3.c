#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    return new;
}

void append(struct Node** head, int data) {
    struct Node* new = createNode(data);
    if (*head == NULL) {
        *head = new;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
}

struct Node* removeEveryKthNode(struct Node* head, int k) {
    if (k <= 0 || head == NULL)
        return head;
    if (k == 1) {
        while (head != NULL) {
            struct Node* temp = head;
            head = head->next;
            free(temp);
        }
        return NULL;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    int count = 1;

    while (current != NULL) {
        if (count % k == 0) {
            struct Node* temp = current;
            prev->next = current->next;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
        count++;
    }

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, val, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }
    scanf("%d", &k);
    head = removeEveryKthNode(head, k);
    printList(head);
    return 0;
}
