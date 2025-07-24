#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int stack[MAX];
int top = -1;
void push(int index) 
{
    stack[++top] = index;
}
int pop() 
{
    return stack[top--];
}
int isEmpty() 
{
    return top == -1;
}
int peek() 
{
    return stack[top];
}
void calculateSpan(int price[], int n, int span[]) 
{
    top = -1;  
    push(0);
    span[0] = 1;  
    for (int i = 1; i < n; i++) 
    {
        while (!isEmpty() && price[peek()] <= price[i]) 
        {
            pop();
        }
        span[i] = isEmpty() ? (i + 1) : (i - peek());
        push(i);
    }
}
int main() 
{
    int n;
    int price[MAX], span[MAX];
    printf("Enter the number of days: ");
    scanf("%d", &n);
    printf("Enter stock prices for each day:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &price[i]);
    }
    calculateSpan(price, n, span);
    printf("\nStock Spans:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Day %d (Price: %d) → Span: %d\n", i + 1, price[i], span[i]);
    }
    return 0;
}
