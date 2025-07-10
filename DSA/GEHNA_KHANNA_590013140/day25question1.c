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
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    while (curr) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int isPalindrome(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* second = reverse(slow);
    struct Node* first = head;

    while (second) {
        if (first->data != second->data)
            return 0;
        first = first->next;
        second = second->next;
    }

    return 1;
}

int main() {
    struct Node* head = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }

    if (isPalindrome(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
