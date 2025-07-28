#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int d; 
    struct Node* n;
};
struct Queue 
{
    struct Node *f, *r; 
};
struct Stack 
{
    struct Node* t;
};
struct Node* new(int d) 
{
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->d = d;
    t->n = NULL;
    return t;
}
struct Queue* init_q() 
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->f = q->r = NULL;
    return q;
}
struct Stack* init_s() 
{
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->t = NULL;
    return s;
}
void enq(struct Queue* q, int d) 
{
    struct Node* t = new(d);
    if (!q->r) q->f = q->r = t;
    else {
        q->r->n = t;
        q->r = t;
    }
}
int deq(struct Queue* q) 
{
    if (!q->f) return -1;
    struct Node* t = q->f;
    int d = t->d;
    q->f = t->n;
    if (!q->f) q->r = NULL;
    free(t);
    return d;
}
void push(struct Stack* s, int d) 
{
    struct Node* t = new(d);
    t->n = s->t;
    s->t = t;
}
int pop(struct Stack* s) 
{
    if (!s->t) return -1;
    struct Node* t = s->t;
    int d = t->d;
    s->t = t->n;
    free(t);
    return d;
}
int count(struct Queue* q) 
{
    int c = 0;
    struct Node* t = q->f;
    while (t) 
    {
        c++;
        t = t->n;
    }
    return c;
}
void rev_k(struct Queue* q, int k) 
{
    if (!q->f || k <= 0 || k > count(q)) return;
    struct Stack* s = init_s();
    for (int i = 0; i < k; i++) 
    {
        int d = deq(q);
        if (d != -1) push(s, d);
    }
    while (s->t) enq(q, pop(s));
    for (int i = 0; i < count(q) - k; i++) 
    {
        int d = deq(q);
        enq(q, d);
    }
    free(s);
}
void print(struct Queue* q) 
{
    struct Node* t = q->f;
    printf("Queue: ");
    while (t) 
    {
        printf("%d ", t->d);
        t = t->n;
    }
    printf("\n");
}
int main() 
{
    struct Queue* q = init_q();
    int n, k, x;    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &x);
        enq(q, x);
    }
    printf("Enter k (elements to reverse): ");
    scanf("%d", &k);
    printf("Original ");
    print(q);
    rev_k(q, k);
    printf("After reversing first %d elements ", k);
    print(q);    
    while (q->f) deq(q);
    free(q);
    return 0;
}
