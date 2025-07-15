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
struct Node* del(struct Node* lst, int pos) 
{
    if (!lst || pos < 1) return lst;
    if (pos == 1) 
    {
        struct Node* d = lst;
        lst = lst->fwd;
        if (lst) lst->bck = NULL;
        free(d);
        return lst;
    }
    struct Node* c = lst;
    int i = 1;
    while (c && i < pos) 
    {
        c = c->fwd;
        i++;
    }
    if (!c) return lst;
    if (c->bck) c->bck->fwd = c->fwd;
    if (c->fwd) c->fwd->bck = c->bck;
    free(c);
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
    int pos = 2;
    lst = del(lst, pos);
    printf("After deleting %dth node: ", pos);
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
