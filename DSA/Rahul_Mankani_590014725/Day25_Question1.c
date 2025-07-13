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
struct Node* p = NULL;
struct Node* c = lst;
struct Node* nx;
while (c) 
{
nx = c->lnk;
c->lnk = p;
p = c;
c = nx;
}
return p;
}
int isPal(struct Node* lst) 
{
if (!lst || !lst->lnk) return 1;
struct Node* slow = lst;
struct Node* fast = lst;
struct Node* p = NULL;
while (fast->lnk && fast->lnk->lnk) 
{
p = slow;
slow = slow->lnk;
fast = fast->lnk->lnk;
}
struct Node* mid = slow->lnk;
p->lnk = NULL;
mid = revList(mid);
struct Node* c1 = lst;
struct Node* c2 = mid;
while (c1 && c2) 
{
if (c1->n != c2->n) return 0;
c1 = c1->lnk;
c2 = c2->lnk;
}
return 1;
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
lst->lnk->lnk = mkNode(2);
lst->lnk->lnk->lnk = mkNode(1);
printf("List: ");
show(lst);
printf("Is Palindrome: %d\n", isPal(lst));
struct Node* c = lst;
struct Node* nx;
while (c) {
nx = c->lnk;
free(c);
c = nx;
}
return 0;
}
