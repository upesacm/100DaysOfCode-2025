#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* head2 = NULL;

void createNode(struct node**, int);
void Print(struct node**);
struct node* Reverse(struct node*);
struct node* Add(struct node*, struct node*);

int main() {
    createNode(&head, 1);
    createNode(&head, 9);
    createNode(&head, 0);

    createNode(&head2, 2);
    createNode(&head2, 5);

    Print(&head);
    Print(&head2);

    head = Reverse(head);
    head2 = Reverse(head2);

    struct node* result = Add(head, head2);
    result = Reverse(result);

    Print(&result);

    return 0;
}

void createNode(struct node** ll, int data) {
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node->data = data;
    Node->next = NULL;
    if (*ll == NULL) {
        *ll = Node;
        return;
    }
    struct node* current = *ll;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = Node;
}

void Print(struct node** ll) {
    struct node* current = *ll;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct node* Reverse(struct node* head) {
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct node* Add(struct node* l1, struct node* l2) {
    struct node* new_list = NULL;
    struct node* tail = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }
        struct node* Node = (struct node*)malloc(sizeof(struct node));
        Node->data = sum % 10;
        Node->next = NULL;
        carry = sum / 10;

        if (new_list == NULL) {
            new_list = Node;
            tail = Node;
        } else {
            tail->next = Node;
            tail = Node;
        }
    }

    while (new_list != NULL && new_list->data == 0 && new_list->next != NULL) {
        new_list = new_list->next;
    }

    return new_list;
}
