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
void delete_middle(int pos, int size) 
{
    if (pos == size / 2 + 1) 
    {
        pop();
        return;
    }
    int temp = pop();
    delete_middle(pos + 1, size);
    push(temp);
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
    printf("Original ");
    print_stack();
    if (n > 0) 
    {
        delete_middle(1, n);
        printf("After deleting middle ");
        print_stack();
    } 
    else 
    {
        printf("Empty stack\n");
    }
    return 0;
}
