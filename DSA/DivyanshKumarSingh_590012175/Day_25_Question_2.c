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

struct Node *intersection(struct Node *h1, struct Node *h2)
{
    struct Node *res = NULL;
    struct Node *tail = NULL;
    while (h1 && h2)
    {
        if (h1->data == h2->data)
        {
            struct Node *temp = malloc(sizeof(struct Node));
            temp->data = h1->data;
            temp->next = NULL;
            if (!res)
                res = tail = temp;
            else
            {
                tail->next = temp;
                tail = temp;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
        else if (h1->data < h2->data)
        {
            h1 = h1->next;
        }
        else
        {
            h2 = h2->next;
        }
    }
    return res;
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
    int n1, n2, x;
    struct Node *head1 = NULL, *head2 = NULL;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &x);
        head1 = insert(head1, x);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &x);
        head2 = insert(head2, x);
    }
    struct Node *res = intersection(head1, head2);
    print(res);
    return 0;
}
