#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int x) 
{
    if (top >= MAX - 1) 
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}
int pop() 
{
    if (top == -1) 
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}
void insertAtBottom(int x) 
{
    if (top == -1) 
    {
        push(x);
        return;
    }
    int temp = pop();
    insertAtBottom(x);
    push(temp);
}
void reverseStack() 
{
    if (top == -1)
        return;
    int temp = pop();
    reverseStack();
    insertAtBottom(temp);
}
void display() 
{
    if (top == -1) 
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) 
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main() 
{
    int n, val;
    printf("Enter number of elements in stack: ");
    scanf("%d", &n);
    printf("Enter elements (top to bottom):\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        push(val);
    }
    printf("\nOriginal Stack:\n");
    display();
    reverseStack();
    printf("\nReversed Stack:\n");
    display();
    return 0;
}
