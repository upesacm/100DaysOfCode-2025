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
struct node* deletemiddle(struct node* head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node *slow = head, *fast = head, *prev = NULL;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = slow->next;
    free(slow);
    return head;
}
int main() {
    int n;
    struct node* head = NULL;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    head = createlist(n);
    printf("Original linked list: ");
    display(head);
    head = deletemiddle(head);
    printf("Linked list after deleting middle node: ");
    display(head);
    return 0;
}
