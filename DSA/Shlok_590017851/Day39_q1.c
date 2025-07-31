#include <stdio.h>
#define MAX 100

void insertAtBottom(int stack[], int* top, int value) 
{
    if (*top == -1) 
    {
        stack[++(*top)] = value;
    } 
    else 
    {
        int temp = stack[(*top)--];
        insertAtBottom(stack, top, value);
        stack[++(*top)] = temp;
    }
}
void reverseStack(int stack[], int* top) 
{
    if (*top == -1) return;
    int temp = stack[(*top)--];
    reverseStack(stack, top);
    insertAtBottom(stack, top, temp);
}
void printStack(int stack[], int top)
{
    for (int i = 0; i <= top; i++) 
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main() 
{
    int stack[MAX];
    int top = -1;

  stack[++top] = 1;
    stack[++top] = 2;
    stack[++top] = 3;
    printf("Original Stack:\n");
    printStack(stack, top);

    reverseStack(stack, &top);
    printf("Reversed Stack:\n");
    printStack(stack, top);
    return 0;
}
