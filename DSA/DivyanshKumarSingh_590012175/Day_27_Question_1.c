#include <stdio.h>
#include <stdlib.h>

struct DNode
{
    int data;
    struct DNode *prev, *next;
};

struct DNode *insert(struct DNode *head, int val)
{
    struct DNode *temp = malloc(sizeof(struct DNode));
    temp->data = val;
    temp->prev = temp->next = NULL;
    if (!head)
        return temp;
    struct DNode *curr = head;
    while (curr->next)
        curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
    return head;
}

struct DNode *deleteAt(struct DNode *head, int pos)
{
    if (!head)
        return NULL;
    struct DNode *curr = head;
    for (int i = 1; i < pos && curr; i++)
        curr = curr->next;
    if (!curr)
        return head;
    if (curr->prev)
        curr->prev->next = curr->next;
    else
        head = curr->next;
    if (curr->next)
        curr->next->prev = curr->prev;
    free(curr);
    return head;
}

void print(struct DNode *head)
{
    while (head)
    {
        printf("%d", head->data);
        if (head->next)
            printf(" <--> ");
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int n, x, pos;
    struct DNode *head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insert(head, x);
    }
    scanf("%d", &pos);
    head = deleteAt(head, pos);
    print(head);
    return 0;
}
