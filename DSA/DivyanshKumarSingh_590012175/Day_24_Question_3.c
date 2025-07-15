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

struct Node *deleteAtPos(struct Node *head, int pos)
{
    if (pos == 1)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node *curr = head;
    for (int i = 1; i < pos - 1 && curr; i++)
        curr = curr->next;
    if (!curr || !curr->next)
        return head;
    struct Node *del = curr->next;
    curr->next = del->next;
    free(del);
    return head;
}

void print(struct Node *head)
{
    while (head)
    {
        printf("%d", head->data);
        if (head->next)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int n, x, pos;
    struct Node *head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insert(head, x);
    }
    scanf("%d", &pos);
    head = deleteAtPos(head, pos);
    print(head);
    return 0;
}
