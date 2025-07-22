#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Stack node definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack functions
void push(Node** top, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = *top;
    *top = temp;
}

int pop(Node** top) {
    if (*top == NULL) return -1;
    Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int peek(Node* top) {
    return top ? top->data : -1;
}

int isEmpty(Node* top) {
    return top == NULL;
}

int size(Node* top) {
    int count = 0;
    while (top) {
        count++;
        top = top->next;
    }
    return count;
}

// 1. Sort Stack using Another Stack
void sortStack(Node** input) {
    Node* tempStack = NULL;
    while (!isEmpty(*input)) {
        int tmp = pop(input);
        while (!isEmpty(tempStack) && peek(tempStack) > tmp) {
            push(input, pop(&tempStack));
        }
        push(&tempStack, tmp);
    }
    // Copy back to original
    while (!isEmpty(tempStack)) {
        push(input, pop(&tempStack));
    }
}

// 2. Evaluate Postfix Expression
int evaluatePostfix(char* expr) {
    Node* stack = NULL;
    for (int i = 0; expr[i]; i++) {
        char c = expr[i];
        if (isdigit(c)) {
            push(&stack, c - '0');
        } else {
            int b = pop(&stack);
            int a = pop(&stack);
            switch (c) {
                case '+': push(&stack, a + b); break;
                case '-': push(&stack, a - b); break;
                case '*': push(&stack, a * b); break;
                case '/': push(&stack, a / b); break;
            }
        }
    }
    return pop(&stack);
}

// 3. Delete Middle Element
void deleteMiddle(Node** top, int current, int mid) {
    if (*top == NULL) return;

    int x = pop(top);
    if (current != mid) {
        deleteMiddle(top, current + 1, mid);
        push(top, x);
    } else {
        // middle element skipped
    }
}

void deleteMiddleWrapper(Node** top) {
    int n = size(*top);
    int mid = n / 2;
    deleteMiddle(top, 0, mid);
}

// Utility to print the stack (top to bottom)
void printStack(Node* top) {
    Node* temp = top;
    printf("[");
    while (temp) {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp) printf(", ");
    }
    printf("]\n");
}

// ---------------------------- MAIN ----------------------------

int main() {
    // Task 1: Sort Stack
    Node* s1 = NULL;
    push(&s1, 3); push(&s1, 1); push(&s1, 4); push(&s1, 2);
    printf("Original Stack: ");
    printStack(s1);
    sortStack(&s1);
    printf("Sorted Stack: ");
    printStack(s1);

    // Task 2: Evaluate Postfix
    char expr1[] = "231*+9-";
    printf("Postfix Expression: %s => Result: %d\n", expr1, evaluatePostfix(expr1));

    // Task 3: Delete Middle Element
    Node* s2 = NULL;
    push(&s2, 5); push(&s2, 4); push(&s2, 3); push(&s2, 2); push(&s2, 1);
    printf("Original Stack: ");
    printStack(s2);
    deleteMiddleWrapper(&s2);
    printf("After Deleting Middle: ");
    printStack(s2);

    return 0;
}
