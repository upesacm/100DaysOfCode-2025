#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct TwoStacks 
{
    int arr[MAX];
    int top1;
    int top2;
    int size;
} 
TwoStacks;
void init(TwoStacks* ts, int size) 
{
    ts->size = size;
    ts->top1 = -1;
    ts->top2 = size;
}
void push1(TwoStacks* ts, int value) 
{
    if (ts->top1 + 1 == ts->top2)
    {
        printf("Stack Overflow in Stack1\n");
        return;
    }
    ts->arr[++ts->top1] = value;
}
void push2(TwoStacks* ts, int value) 
{
    if (ts->top1 + 1 == ts->top2)
    {
        printf("Stack Overflow in Stack2\n");
        return;
    }
    ts->arr[--ts->top2] = value;
}
int pop1(TwoStacks* ts) 
{
    if (ts->top1 == -1)
    {
        printf("Stack Underflow in Stack1\n");
        return -1;
    }
    return ts->arr[ts->top1--];
}
int pop2(TwoStacks* ts)
{
    if (ts->top2 == ts->size)
    {
        printf("Stack Underflow in Stack2\n");
        return -1;
    }
    return ts->arr[ts->top2++];
}
void printStack1(TwoStacks* ts) 
{
    printf("Stack1: ");
    for (int i = 0; i <= ts->top1; i++) 
    {
        printf("%d ", ts->arr[i]);
    }
    printf("\n");
}
void printStack2(TwoStacks* ts) 
{
    printf("Stack2: ");
    for (int i = ts->size - 1; i >= ts->top2; i--) 
    {
        printf("%d ", ts->arr[i]);
    }
    printf("\n");
}
int main() 
{
    TwoStacks ts;
    init(&ts, MAX);

  push1(&ts, 1);
    push1(&ts, 2);
    push2(&ts, 9);
    push2(&ts, 8);
    printStack1(&ts);
    printStack2(&ts);

    push1(&ts, 3);
    pop2(&ts);
    printStack1(&ts);
    printStack2(&ts);
    return 0;
}
