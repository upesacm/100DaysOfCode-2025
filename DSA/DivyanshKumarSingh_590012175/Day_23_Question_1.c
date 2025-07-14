#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insert(struct Node *head, int val)
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if (!head)
        return temp;
    struct Node *curr = head;
    while (curr->next)
        curr = curr->next;
    curr->next = temp;
    return head;
}

int kthFromEnd(struct Node *head, int k)
{
    struct Node *p1 = head;
    struct Node *p2 = head;
    for (int i = 0; i < k; i++)
    {
        if (!p2)
            return -1;
        p2 = p2->next;
    }
    while (p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1 ? p1->data : -1;
}

int main()
{
    int n, x, k;
    struct Node *head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insert(head, x);
    }
    scanf("%d", &k);
    printf("%d\n", kthFromEnd(head, k));
    return 0;
}
