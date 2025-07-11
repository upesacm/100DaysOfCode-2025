#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int n;
    struct Node* lnk;
};
struct Node* mkNode(int n) 
{
    struct Node* nd = (struct Node*)malloc(sizeof(struct Node));
    nd->n = n;
    nd->lnk = NULL;
    return nd;
}
struct Node* sort(struct Node* lst) 
{
    if (!lst || !lst->lnk) return lst;
    struct Node* z = NULL;
    struct Node* zt = NULL;
    struct Node* o = NULL;
    struct Node* ot = NULL;
    struct Node* t = NULL;
    struct Node* tt = NULL;
    struct Node* c = lst;
    while (c) 
    {
        struct Node* nx = c->lnk;
        c->lnk = NULL;
        if (c->n == 0) 
        {
            if (!z) z = c;
            else zt->lnk = c;
            zt = c;
        } 
        else if (c->n == 1) 
        {
            if (!o) o = c;
            else ot->lnk = c;
            ot = c;
        } 
        else 
        {
            if (!t) t = c;
            else tt->lnk = c;
            tt = c;
        }
        c = nx;
    }
    if (z) 
    {
        lst = z;
        if (o) zt->lnk = o;
        else if (t) zt->lnk = t;
    } 
    else if (o) 
    {
        lst = o;
        if (t) ot->lnk = t;
    } 
    else 
    {
        lst = t;
    }
    return lst;
}
void show(struct Node* lst) 
{
    struct Node* c = lst;
    while (c) 
    {
        printf("%d ", c->n);
        c = c->lnk;
    }
    printf("\n");
}
int main() 
{
    struct Node* lst = mkNode(1);
    lst->lnk = mkNode(2);
    lst->lnk->lnk = mkNode(0);
    lst->lnk->lnk->lnk = mkNode(1);
    lst->lnk->lnk->lnk->lnk = mkNode(2);
    printf("List: ");
    show(lst);
    lst = sort(lst);
    printf("Sorted: ");
    show(lst);
    struct Node* c = lst;
    struct Node* nx;
    while (c) 
    {
        nx = c->lnk;
        free(c);
        c = nx;
    }
    return 0;
}
