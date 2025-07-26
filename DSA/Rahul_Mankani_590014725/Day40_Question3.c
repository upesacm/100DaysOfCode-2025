#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
typedef struct 
{
    int s[MAX], m[MAX], top;
} MaxStack;
void init(MaxStack* ms) 
{
    ms->top = -1;
}
void push(MaxStack* ms, int x) 
{
    if(ms->top < MAX-1) 
    {
        ms->s[++ms->top] = x;
        ms->m[ms->top] = ms->top == 0 || x > ms->m[ms->top-1] ? x : ms->m[ms->top-1];
    }
}
int pop(MaxStack* ms) 
{
    if(ms->top >= 0) return ms->s[ms->top--];
    return -1;
}
int top(MaxStack* ms) 
{
    if(ms->top >= 0) return ms->s[ms->top];
    return -1;
}
int getMax(MaxStack* ms) 
{
    if(ms->top >= 0) return ms->m[ms->top];
    return -1;
}
int main() 
{
    MaxStack ms;
    init(&ms);
    int q, op, x;
    scanf("%d", &q);
    while(q--) 
    {
        scanf("%d", &op);
        if(op == 1) 
        {
            scanf("%d", &x);
            push(&ms, x);
        } 
        else if(op == 2) 
        {
            printf("%d\n", pop(&ms));
        } 
        else if(op == 3) 
        {
            printf("%d\n", top(&ms));
        } 
        else if(op == 4) 
        {
            printf("%d\n", getMax(&ms));
        }
    }
    return 0;
}
