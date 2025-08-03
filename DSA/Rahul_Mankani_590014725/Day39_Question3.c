#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
typedef struct 
{
    int a[MAX], t1, t2;
} TwoStacks;
void init(TwoStacks* ts) 
{
    ts->t1 = -1;
    ts->t2 = MAX;
}
int push1(TwoStacks* ts, int x) 
{
    if(ts->t1 + 1 < ts->t2) 
    {
        ts->a[++ts->t1] = x;
        return 1;
    }
    return 0;
}
int push2(TwoStacks* ts, int x) 
{
    if(ts->t2 - 1 > ts->t1) 
    {
        ts->a[--ts->t2] = x;
        return 1;
    }
    return 0;
}
int pop1(TwoStacks* ts) 
{
    if(ts->t1 >= 0) return ts->a[ts->t1--];
    return -1;
}
int pop2(TwoStacks* ts) 
{
    if(ts->t2 < MAX) return ts->a[ts->t2++];
    return -1;
}
int main() 
{
    TwoStacks ts;
    init(&ts);
    int q, s, x;
    scanf("%d", &q);
    while(q--) 
    {
        scanf("%d%d", &s, &x);
        if(s == 1) 
        {
            printf("%d\n", x == 1 ? push1(&ts, x) : pop1(&ts));
        } 
        else 
        {
            printf("%d\n", x == 1 ? push2(&ts, x) : pop2(&ts));
        }
    }
    return 0;
}
