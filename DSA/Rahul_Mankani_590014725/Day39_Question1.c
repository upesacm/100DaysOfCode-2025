#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
typedef struct 
{
    int s[MAX], top;
} Stack;
void init(Stack* st) 
{
    st->top = -1;
}
void push(Stack* st, int x) 
{
    if(st->top < MAX-1) st->s[++st->top] = x;
}
int pop(Stack* st) 
{
    if(st->top >= 0) return st->s[st->top--];
    return -1;
}
int Empty(Stack* st) 
{
    return st->top < 0;
}
void insertBottom(Stack* st, int x) 
{
    if(Empty(st)) 
    {
        push(st, x);
        return;
    }
    int t = pop(st);
    insertBottom(st, x);
    push(st, t);
}
void reverse(Stack* st) 
{
    if(Empty(st)) return;
    int x = pop(st);
    reverse(st);
    insertBottom(st, x);
}
int main() 
{
    Stack st;
    init(&st);
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &x);
        push(&st, x);
    }
    reverse(&st);
    while(!Empty(&st)) 
    {
        printf("%d ", pop(&st));
    }
    printf("\n");
    return 0;
}
