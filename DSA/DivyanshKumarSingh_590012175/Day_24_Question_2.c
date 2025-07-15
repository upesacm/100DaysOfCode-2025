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

struct Node *deleteNM(struct Node *head, int m, int n)
{
    struct Node *curr = head;
    struct Node *temp;

    while (curr)
    {
        for (int i = 1; i < m && curr != NULL; i++)
            curr = curr->next;

        if (curr == NULL)
            break;

        temp = curr->next;

        for (int i = 0; i < n && temp != NULL; i++)
        {
            struct Node *del = temp;
            temp = temp->next;
            free(del);
        }

        curr->next = temp;

        curr = temp;
    }

    return head;
}

void print(struct Node *head)
{
    while (head)
    {
        printf("%d", head->data);
        if (head->next)
            printf("->");
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int n, x, m, d;
    struct Node *head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insert(head, x);
    }
    scanf("%d %d", &m, &d);
    head = deleteNM(head, m, d);
    print(head);
    return 0;
}
