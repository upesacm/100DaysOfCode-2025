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
struct Node* swapKth(struct Node* lst, int k) 
{
    if (!lst || k < 1) return lst;
    struct Node* c = lst;
    int i = 1;
    struct Node* p1 = NULL;
    struct Node* c1 = lst;
    while (c && i < k) 
    {
        p1 = c1;
        c1 = c1->lnk;
        c = c->lnk;
        i++;
    }
    if (!c1 || !c) return lst;
    struct Node* p2 = NULL;
    struct Node* c2 = c->lnk;
    while (c2 && c2->lnk) 
    {
        p2 = c2;
        c2 = c2->lnk;
        c = c->lnk;
    }
    if (!c2 || c1 == c2) return lst;
    if (p1) p1->lnk = c2;
    else lst = c2;
    if (p2) p2->lnk = c1;
    else lst = c1;
    struct Node* t = c1->lnk;
    c1->lnk = c2->lnk;
    c2->lnk = t;
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
    lst = swapKth(lst, k);
    printf("After swapping %dth nodes: ", k);
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
