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
        exit(1);
    }
    s->data[++(s->top)] = value;
}
int pop(Stack *s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}
int size(Stack *s) 
{
    return s->top + 1;
}
void deleteMiddle(Stack *s, int current, int mid) 
{
    if (current == mid) 
    {
        pop(s);
        return;
    }
    int temp = pop(s); 
    deleteMiddle(s, current + 1, mid); 
    push(s, temp);
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
    Stack s;
    init(&s);
    int n, val;
    printf("Enter number of elements in the stack: ");
    scanf("%d", &n);
    printf("Enter %d elements (top element first):\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        push(&s, val);
    }
    printf("Original stack (top to bottom): ");
    printStack(&s);
    int mid = size(&s) / 2; 
    deleteMiddle(&s, 0, mid);
    printf("Stack after deleting middle element: ");
    printStack(&s);
    return 0;
}
