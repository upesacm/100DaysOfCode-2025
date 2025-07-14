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
void rmDups(struct Node* lst) 
{
    if (lst == NULL || lst->lnk == NULL) 
    {
        return;
    }
    struct Node* c = lst;
    while (c != NULL && c->lnk != NULL) 
    {
        if (c->n == c->lnk->n) 
        {
            struct Node* tmp = c->lnk;
            c->lnk = c->lnk->lnk;
            free(tmp);
        } 
        else 
        {
            c = c->lnk;
        }
    }
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
    lst->lnk = mkNode(1);
    lst->lnk->lnk = mkNode(2);
    lst->lnk->lnk->lnk = mkNode(3);
    lst->lnk->lnk->lnk->lnk = mkNode(3);
    printf("Original List: ");
    show(lst);
    rmDups(lst);
    printf("List after removing duplicates: ");
    show(lst);
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
