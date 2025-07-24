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
void push(Stack *s, int val) 
{
    if (s->top == MAX - 1) 
    {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = val;
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
int peek(Stack *s) 
{
    return s->data[s->top];
}
int main() 
{
    int arr[MAX], result[MAX];
    int n;
    Stack s;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
        result[i] = -1;  
    }
    init(&s);
    for (int i = 0; i < n; i++) 
    {
        while (!isEmpty(&s) && arr[i] > arr[peek(&s)]) 
        {
            int idx = pop(&s);
            result[idx] = arr[i];
        }
        push(&s, i);
    }
    printf("Next Greater Elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", arr[i], result[i]);
    }
    return 0;
}
