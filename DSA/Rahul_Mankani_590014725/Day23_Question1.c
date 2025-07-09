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
int findKth(struct Node* lst, int k) 
{
    if (lst == NULL || k <= 0) 
    {
        return -1;
    }
    struct Node* a = lst;
    struct Node* b = lst;
    for (int i = 0; i < k; i++) 
    {
        if (a == NULL) 
        {
            return -1;
        }
        a = a->lnk;
    }
    while (a != NULL) 
    {
        a = a->lnk;
        b = b->lnk;
    }
    return b->n;
}
void show(struct Node* lst) 
{
    struct Node* c = lst;
    while (c != NULL) 
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
    printf("Linked List: ");
    show(lst);
    int k = 2;
    int r = findKth(lst, k);
    printf("Value of %dth node from end: %d\n", k, r);
    k = 1;
    r = findKth(lst, k);
    printf("Value of %dth node from end: %d\n", k, r);
    k = 6;
    r = findKth(lst, k);
    printf("Value of %dth node from end: %d\n", k, r);
    struct Node* c = lst;
    struct Node* nx;
    while (c != NULL) 
    {
        nx = c->lnk;
        free(c);
        c = nx;
    }
    return 0;
}
