#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int n;
    struct Node* fwd;
    struct Node* bck;
};
struct Node* mkNode(int n) 
{
    struct Node* nd = (struct Node*)malloc(sizeof(struct Node));
    nd->n = n;
    nd->fwd = NULL;
    nd->bck = NULL;
    return nd;
}
struct Node* reverse(struct Node* lst) 
{
    if (!lst || !lst->fwd) return lst;
    struct Node* c = lst;
    struct Node* t;
    while (c) 
    {
        t = c->fwd;
        c->fwd = c->bck;
        c->bck = t;
        lst = c;
        c = t;
    }
    return lst;
}
void show(struct Node* lst) 
{
    struct Node* c = lst;
    while (c) 
    {
        printf("%d ", c->n);
        c = c->fwd;
    }
    printf("\n");
}
int main() 
{
    struct Node* lst = mkNode(1);
    lst->fwd = mkNode(2);
    lst->fwd->bck = lst;
    lst->fwd->fwd = mkNode(3);
    lst->fwd->fwd->bck = lst->fwd;
    lst->fwd->fwd->fwd = mkNode(4);
    lst->fwd->fwd->fwd->bck = lst->fwd->fwd;
    printf("List: ");
    show(lst);
    lst = reverse(lst);
    printf("Reversed: ");
    show(lst);
    struct Node* c = lst;
    struct Node* nx;
    while (c) 
    {
        nx = c->fwd;
        free(c);
        c = nx;
    }
    return 0;
}
