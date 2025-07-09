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
struct Node* delMid(struct Node* lst) 
{
    if (lst == NULL || lst->lnk == NULL) 
    {
        free(lst);
        return NULL;
    }
    struct Node* slow = lst;
    struct Node* fast = lst;
    struct Node* prev = NULL;
    while (fast != NULL && fast->lnk != NULL) 
    {
        prev = slow;
        slow = slow->lnk;
        fast = fast->lnk->lnk;
    }
    prev->lnk = slow->lnk;
    free(slow);
    return lst;
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
    lst = delMid(lst);
    printf("List after deleting middle: ");
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
