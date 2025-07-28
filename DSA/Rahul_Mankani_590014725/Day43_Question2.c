#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    char* s;
    struct Node* n;
};
struct Queue 
{
    struct Node *f, *r;
};
struct Node* new(char* s) 
{
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->s = strdup(s);
    t->n = NULL;
    return t;
}
struct Queue* init_q() 
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->f = q->r = NULL;
    return q;
}
void enq(struct Queue* q, char* s) 
{
    struct Node* t = new(s);
    if (!q->r) q->f = q->r = t;
    else 
    {
        q->r->n = t;
        q->r = t;
    }
}
char* deq(struct Queue* q) 
{
    if (!q->f) return NULL;
    struct Node* t = q->f;
    char* s = t->s;
    q->f = t->n;
    if (!q->f) q->r = NULL;
    free(t);
    return s;
}
char** gen_bin(int n, int* sz) 
{
    struct Queue* q = init_q();
    char** r = (char**)malloc(n * sizeof(char*));
    *sz = 0;
    enq(q, "1");
    while (q->f) 
    {
        char* s = deq(q);
        int v = strtol(s, NULL, 2);
        if (v > n) 
        {
            free(s);
            break;
        }
        r[*sz] = s;
        (*sz)++;
        char* s0 = (char*)malloc(strlen(s) + 2);
        char* s1 = (char*)malloc(strlen(s) + 2);
        strcpy(s0, s);
        strcpy(s1, s);
        strcat(s0, "0");
        strcat(s1, "1");
        enq(q, s0);
        enq(q, s1);
    }
    while (q->f) 
    {
        char* s = deq(q);
        free(s);
    }
    free(q);
    return r;
}
int main() 
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int sz;
    char** r = gen_bin(n, &sz);
    printf("Binary numbers from 1 to %d:\n", n);
    for (int i = 0; i < sz; i++) 
    {
        printf("%s ", r[i]);
        free(r[i]);
    }
    printf("\n");
    free(r);
    return 0;
}
