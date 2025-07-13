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
struct Node* del(struct Node* lst, int m, int n) 
{
    if (!lst || m < 0 || n < 0) return lst;
    struct Node* c = lst;
    struct Node* p = NULL;
    while (c) 
    {
        int i = m;
        while (i-- && c) 
        {
            p = c;
            c = c->lnk;
        }
        if (!c) break;
        int j = n;
        while (j-- && c) 
        {
            struct Node* d = c;
            c = c->lnk;
            free(d);
        }
        if (p) p->lnk = c;
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
    lst->lnk->lnk = mkNode(3);
    lst->lnk->lnk->lnk = mkNode(4);
    printf("List: ");
    show(lst);
    int m = 1;
    int n = 1;
    lst = del(lst, m, n);
    printf("After deleting %d node(s) after every %d node(s): ", n, m);
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
