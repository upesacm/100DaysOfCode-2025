#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
typedef struct 
{
    int s[MAX], m[MAX], top;
} MinStack;
void init(MinStack* ms) 
{
    ms->top = -1;
}
void push(MinStack* ms, int x) 
{
    ms->s[++ms->top] = x;
    if(ms->top == 0 || x <= ms->m[ms->top-1]) 
    {
        ms->m[ms->top] = x;
    } 
    else 
    {
        ms->m[ms->top] = ms->m[ms->top-1];
    }
}
void pop(MinStack* ms) 
{
    if(ms->top >= 0) ms->top--;
}
int top(MinStack* ms) 
{
    return ms->top >= 0 ? ms->s[ms->top] : -1;
}
int getMin(MinStack* ms) 
{
    return ms->top >= 0 ? ms->m[ms->top] : -1;
}
int main() 
{
    MinStack ms;
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
            pop(&ms);
        } 
        else if(op == 3) 
        {
            printf("%d\n", top(&ms));
        } 
        else if(op == 4) 
        {
            printf("%d\n", getMin(&ms));
        }
    }
    return 0;
}
