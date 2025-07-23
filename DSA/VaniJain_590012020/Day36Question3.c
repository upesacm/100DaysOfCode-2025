#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Stack 
{
    int arr[MAX];
    int top;
};
void initStack(struct Stack* stack) 
{
    stack->top = -1;
}
int isEmpty(struct Stack* stack) 
{
    return stack->top == -1;
}
int isFull(struct Stack* stack) 
{
    return stack->top == MAX - 1;
}
void push(struct Stack* stack, int x) 
{
    if (!isFull(stack)) 
    {
        stack->arr[++stack->top] = x;
    }
}
int pop(struct Stack* stack) 
{
    if (!isEmpty(stack)) 
    {
        return stack->arr[stack->top--];
    }
    return -1; 
}
void insertAtBottom(struct Stack* stack, int x) {
    if (isEmpty(stack)) 
    {
        push(stack, x);
    } else 
    {
        int temp = pop(stack);
        insertAtBottom(stack, x);
        push(stack, temp);
    }
}
void printStack(struct Stack* stack) 
{
    printf("Stack (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) 
    {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}
int main()
{
    struct Stack stack;
    int n, x, val;
    initStack(&stack);
    printf("Enter number of elements to push: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        push(&stack, val);
    }
    printf("Enter element to insert at bottom: ");
    scanf("%d", &x);
    insertAtBottom(&stack, x);
    printStack(&stack);
    return 0;
}
