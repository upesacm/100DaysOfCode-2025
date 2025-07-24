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
void sortStack(Stack *stack) 
{
    Stack tempStack;
    init(&tempStack);
    while (!isEmpty(stack)) 
    {
        int temp = pop(stack);
        while (!isEmpty(&tempStack) && peek(&tempStack) > temp) {
            push(stack, pop(&tempStack));
        }
        push(&tempStack, temp);
    }
    while (!isEmpty(&tempStack)) 
    {
        push(stack, pop(&tempStack));
    }
}
void printStack(Stack *s) 
{
    for (int i = s->top; i >= 0; i--) 
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
int main() 
{
    Stack stack;
    init(&stack);
    int n, val;
    printf("Enter number of elements in the stack: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        push(&stack, val);
    }
    printf("Original Stack (top to bottom): ");
    printStack(&stack);
    sortStack(&stack);
    printf("Sorted Stack (top to bottom): ");
    printStack(&stack);
    return 0;
}
