#include <stdio.h>
#define MAX 100

int s1[MAX], s2[MAX], t1 = -1, t2 = -1;
void push(int s[], int *t, int x) 
{
    if (*t < MAX - 1) s[++(*t)] = x;
}
int pop(int s[], int *t) 
{
    if (*t >= 0) return s[(*t)--];
    return -1;
}
void sort_stack() 
{
    while (t1 >= 0) 
    {
        int x = pop(s1, &t1);
        while (t2 >= 0 && s2[t2] > x) 
        {
            push(s1, &t1, pop(s2, &t2));
        }
        push(s2, &t2, x);
    }
    while (t2 >= 0) 
    {
        push(s1, &t1, pop(s2, &t2));
    }
}
void print_stack() 
{
    printf("Stack: ");
    for (int i = 0; i <= t1; i++) printf("%d ", s1[i]);
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
        push(s1, &t1, x);
    }
    printf("Original ");
    print_stack();
    sort_stack();
    printf("Sorted ");
    print_stack();
    return 0;
}
