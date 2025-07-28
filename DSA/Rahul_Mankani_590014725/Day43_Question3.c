#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    char d;
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
struct Node* new(char d) 
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
void enq(struct Queue* q, char d) 
{
    struct Node* t = new(d);
    if (!q->r) q->f = q->r = t;
    else 
    {
        q->r->n = t;
        q->r = t;
    }
}
char deq(struct Queue* q) 
{
    if (!q->f) return '\0';
    struct Node* t = q->f;
    char d = t->d;
    q->f = t->n;
    if (!q->f) q->r = NULL;
    free(t);
    return d;
}
void push(struct Stack* s, char d) 
{
    struct Node* t = new(d);
    t->n = s->t;
    s->t = t;
}
char pop(struct Stack* s) 
{
    if (!s->t) return '\0';
    struct Node* t = s->t;
    char d = t->d;
    s->t = t->n;
    free(t);
    return d;
}
int is_pal(struct Queue* q) 
{
    struct Stack* s = init_s();
    struct Queue* t = init_q();
    struct Node* p = q->f;
    while (p) 
    {
        push(s, p->d);
        enq(t, p->d);
        p = p->n;
    }
    while (q->f) 
    {
        if (deq(q) != pop(s)) 
        {
            while (q->f) deq(q);
            while (s->t) pop(s);
            free(s);
            free(t);
            return 0;
        }
    }
    while (t->f) enq(q, deq(t));
    free(s);
    free(t);
    return 1;
}
int main() 
{
    struct Queue* q = init_q();
    char s[100];
    printf("Enter string: ");
    scanf("%s", s);
    for (int i = 0; s[i]; i++) enq(q, s[i]);
    printf("Is palindrome: %s\n", is_pal(q) ? "Yes" : "No");
    while (q->f) deq(q);
    free(q);
    return 0;
}
