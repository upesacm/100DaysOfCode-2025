#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void push(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (s->top == NULL) {
        return INT_MIN;
    }
    Node* temp = s->top;
    int data = temp->data;
    s->top = temp->next;
    free(temp);
    return data;
}

int peek(Stack* s) {
    if (s->top == NULL) {
        return INT_MIN;
    }
    return s->top->data;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

int main() {
    Stack* mainStack = (Stack*)malloc(sizeof(Stack));
    mainStack->top = NULL;

    Stack* maxStack = (Stack*)malloc(sizeof(Stack));
    maxStack->top = NULL;

    char operation[10];
    int value;

    while (scanf("%s", operation) != EOF) {
        if (strcmp(operation, "Push") == 0) {
            scanf("%d", &value);
            push(mainStack, value);
            if (isEmpty(maxStack) || value >= peek(maxStack)) {
                push(maxStack, value);
            }
        } else if (strcmp(operation, "Pop") == 0) {
            int poppedValue = pop(mainStack);
            if (poppedValue == INT_MIN) {
                printf("Stack is empty\n");
            } else {
                if (poppedValue == peek(maxStack)) {
                    pop(maxStack);
                }
            }
        } else if (strcmp(operation, "getMax") == 0) {
            if (isEmpty(maxStack)) {
                printf("Stack is empty\n");
            } else {
                printf("%d\n", peek(maxStack));
            }
        } else if (strcmp(operation, "exit") == 0) {
            break;
        }
    }

    while (!isEmpty(mainStack)) {
        pop(mainStack);
    }
    free(mainStack);

    while (!isEmpty(maxStack)) {
        pop(maxStack);
    }
    free(maxStack);

    return 0;
}
