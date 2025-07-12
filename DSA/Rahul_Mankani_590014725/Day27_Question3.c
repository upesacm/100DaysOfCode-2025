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
struct Node* remove(struct Node* lst, int k) 
{
    if (!lst || k < 1) return lst;
    if (k == 1) 
    {
        struct Node* c = lst;
        while (c) 
        {
            struct Node* nx = c->lnk;
            free(c);
            c = nx;
        }
        return NULL;
    }
    struct Node* c = lst;
    struct Node* p = NULL;
    int i = 1;
    while (c) 
    {
        if (i == k) 
        {
            if (p) p->lnk = c->lnk;
            else lst = c->lnk;
            struct Node* d = c;
            c = c->lnk;
            free(d);
            i = 1;
        } 
        else 
        {
            p = c;
            c = c->lnk;
            i++;
        }
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
    lst->lnk->lnk->lnk->lnk = mkNode(5);
    printf("List: ");
    show(lst);
    int k = 2;
    lst = remove(lst, k);
    printf("After removing every %dth node: ", k);
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
