#include <stdio.h>
#include <limits.h>
#define MAX 1000
typedef struct 
{
    int val[MAX];
    int max[MAX];
    int top;
} Stack;
void init(Stack *s) 
{
    s->top = -1;
}
int isEmpty(Stack *s) 
{
    return s->top == -1;
}
void push(Stack *s, int x) 
{
    if (s->top == MAX - 1) return; 
    s->top++;
    s->val[s->top] = x;
    if (s->top == 0)
        s->max[s->top] = x;
    else
        s->max[s->top] = (x > s->max[s->top - 1]) ? x : s->max[s->top - 1];
}
int pop(Stack *s) 
{
    if (isEmpty(s)) return INT_MIN; 
    return s->val[s->top--];
}
int getMax(Stack *s) 
{
    if (isEmpty(s)) return INT_MIN;
    return s->max[s->top];
}
void transfer(Stack *in, Stack *out) 
{
    while (!isEmpty(in)) 
    {
        int x = pop(in);
        push(out, x);
    }
}
void slidingWindowMax(int arr[], int n, int k) 
{
    Stack in, out;
    init(&in);
    init(&out);
    for (int i = 0; i < n; i++) 
    {
        push(&in, arr[i]);
        if (i >= k) 
        {
            if (isEmpty(&out)) 
            {
                transfer(&in, &out);
            }
            pop(&out);
        }
        if (i >= k - 1) 
        {
            if (isEmpty(&out)) 
            {
                transfer(&in, &out);
            }
            int maxIn = getMax(&in);
            int maxOut = getMax(&out);
            int currentMax = (maxIn > maxOut) ? maxIn : maxOut;
            printf("%d ", currentMax);
        }
    }
    printf("\n");
}
int main() 
{
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter window size k: ");
    scanf("%d", &k);
    printf("Maximums in each sliding window:\n");
    slidingWindowMax(arr, n, k);
    return 0;
}
