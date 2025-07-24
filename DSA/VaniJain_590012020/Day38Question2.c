#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct 
{
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) 
{
    s->top = -1;
}
int isEmpty(Stack *s) 
{
    return s->top == -1;
}
int isFull(Stack *s) 
{
    return s->top == MAX - 1;
}
void push(Stack *s, int value) 
{
    if (isFull(s)) 
    {
        printf("Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}
int pop(Stack *s) 
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}
int peek(Stack *s) 
{
    if (isEmpty(s)) 
    {
        return -1;
    }
    return s->data[s->top];
}
Stack mainStack, minStack;
void pushValue(int val) 
{
    push(&mainStack, val);
    if (isEmpty(&minStack) || val <= peek(&minStack)) 
    {
        push(&minStack, val);
    }
}
void popValue() 
{
    int val = pop(&mainStack);
    if (val == peek(&minStack)) 
    {
        pop(&minStack);
    }
}

int getTop() 
{
    return peek(&mainStack);
}
int getMin() 
{
    return peek(&minStack);
}
int main() 
{
    init(&mainStack);
    init(&minStack);
    int choice, value;
    while (1) 
    {
        printf("\n--- Min Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Top\n4. Get Min\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                pushValue(value);
                break;
            case 2:
                popValue();
                printf("Top element popped.\n");
                break;
            case 3:
                if (isEmpty(&mainStack))
                    printf("Stack is empty.\n");
                else
                    printf("Top element: %d\n", getTop());
                break;
            case 4:
                if (isEmpty(&minStack))
                    printf("Stack is empty.\n");
                else
                    printf("Minimum element: %d\n", getMin());
                break;

            case 5:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
