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
struct Node* addLists(struct Node* lst1, struct Node* lst2) 
{
    struct Node* res = NULL;
    struct Node* tail = NULL;
    struct Node* c1 = lst1;
    struct Node* c2 = lst2;
    int carry = 0;
    while (c1 || c2 || carry) 
    {
        int sum = carry;
        if (c1) 
        {
            sum += c1->n;
            c1 = c1->lnk;
        }
        if (c2) 
        {
            sum += c2->n;
            c2 = c2->lnk;
        }
        carry = sum / 10;
        struct Node* nd = mkNode(sum % 10);
        if (!res) 
        {
            res = nd;
            tail = nd;
        } 
        else 
        {
            tail->lnk = nd;
            tail = nd;
        }
    }
    return res;
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
    struct Node* lst1 = mkNode(1);
    lst1->lnk = mkNode(9);
    lst1->lnk->lnk = mkNode(0);
    struct Node* lst2 = mkNode(2);
    lst2->lnk = mkNode(5);
    printf("Number 1: ");
    show(lst1);
    printf("Number 2: ");
    show(lst2);
    struct Node* res = addLists(lst1, lst2);
    printf("Sum: ");
    show(res);
    struct Node* c = lst1;
    struct Node* nx;
    while (c) 
    {
        nx = c->lnk;
        free(c);
        c = nx;
    }
    c = lst2;
    while (c) 
    {
        nx = c->lnk;
        free(c);
        c = nx;
    }
    c = res;
    while (c) 
    {
        nx = c->lnk;
        free(c);
        c = nx;
    }
    return 0;
}
