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
struct Node* del(struct Node* lst, int x) 
{
    if (!lst || x < 1) return lst;
    if (x == 1) 
    {
        struct Node* d = lst;
        lst = lst->lnk;
        free(d);
        return lst;
    }
    struct Node* c = lst;
    struct Node* p = NULL;
    int i = 1;
    while (c && i < x) 
    {
        p = c;
        c = c->lnk;
        i++;
    }
    if (!c) return lst;
    p->lnk = c->lnk;
    free(c);
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
    int x = 2;
    lst = del(lst, x);
    printf("After deleting %dth node: ", x);
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
