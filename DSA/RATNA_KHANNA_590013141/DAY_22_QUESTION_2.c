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

int countOccurrences(struct node* head, int key) {
    int count = 0;
    struct node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, key;
    struct node* head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    head = createlist(n);

    printf("The linked list is: ");
    display(head);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int frequency = countOccurrences(head, key);
    printf("The frequency of %d is: %d\n", key, frequency);

    return 0;
}
