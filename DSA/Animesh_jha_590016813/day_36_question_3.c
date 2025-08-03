#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int isEmpty(struct Node *top) {
    return top == NULL;
}

struct Node* push(struct Node *top, int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    return newNode;
}

int pop(struct Node **top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node *temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

void insertAtBottom(struct Node **top, int x) {
    if (isEmpty(*top)) {
        *top = push(*top, x);
        return;
    }

    int temp = pop(top);
    insertAtBottom(top, x);
    *top = push(*top, temp);
}

void printStack(struct Node *top) {
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct Node *top = NULL;

    top = push(top, 3);
    top = push(top, 2);
    top = push(top, 1);

    printf("Original Stack (Top to Bottom):\n");
    printStack(top);

    int x = 0;
    insertAtBottom(&top, x);

    printf("After inserting %d at bottom:\n", x);

    return 0;
}
