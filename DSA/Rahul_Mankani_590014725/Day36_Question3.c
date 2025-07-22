#include <stdio.h>
#define MAX 100

int stk[MAX], top = -1;
void push(int x) 
{
    if (top < MAX - 1) stk[++top] = x;
}
int pop() 
{
    if (top >= 0) return stk[top--];
    return -1;
}
void insert_bottom(int x) 
{
    if (top == -1) 
    {
        push(x);
    } 
    else 
    {
        int temp = pop();
        insert_bottom(x);
        push(temp);
    }
}
void print_stack() 
{
    printf("Stack: ");
    for (int i = 0; i <= top; i++) printf("%d ", stk[i]);
    printf("\n");
}

int main() 
{
    int n, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &x);
        push(x);
    }
    printf("Enter element to insert at bottom: ");
    scanf("%d", &x);
    printf("Original ");
    print_stack();
    insert_bottom(x);
    printf("After inserting %d at bottom ", x);
    print_stack();
    return 0;
}
