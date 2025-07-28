#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int mainStack[MAX];
int maxStack[MAX];
int top = -1;
void push(int x) 
{
    if (top == MAX - 1) 
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    mainStack[top] = x;
    if (top == 0)
        maxStack[top] = x;
    else
        maxStack[top] = (x > maxStack[top - 1]) ? x : maxStack[top - 1];
}
void pop() 
{
    if (top == -1) 
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped: %d\n", mainStack[top]);
    top--;
}
void getMax() 
{
    if (top == -1) 
    {
        printf("Stack is empty. No maximum.\n");
        return;
    }
    printf("Current Maximum: %d\n", maxStack[top]);
}
void display() 
{
    if (top == -1) 
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) 
    {
        printf("%d ", mainStack[i]);
    }
    printf("\n");
}
int main() 
{
    int choice, value;
    while (1) 
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Get Max\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                getMax();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
