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

struct DNode *reverse(struct DNode *head)
{
    struct DNode *temp = NULL;
    struct DNode *curr = head;
    while (curr)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp)
        head = temp->prev;
    return head;
}

void print(struct DNode *head)
{
    while (head)
    {
        printf("%d", head->data);
        if (head->next)
            printf(" <-> ");
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int n, x;
    struct DNode *head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insert(head, x);
    }
    head = reverse(head);
    print(head);
    return 0;
}
