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
struct Node* revList(struct Node* lst) 
{
    struct Node* prev = NULL;
    struct Node* c = lst;
    struct Node* nx;
    while (c != NULL) 
    {
        nx = c->lnk;
        c->lnk = prev;
        prev = c;
        c = nx;
    }
    return prev;
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
    printf("Original List: ");
    show(lst);
    lst = revList(lst);
    printf("Reversed List: ");
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
