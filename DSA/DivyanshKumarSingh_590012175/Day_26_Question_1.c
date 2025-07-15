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

int length(struct Node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

struct Node *swapK(struct Node *head, int k)
{
    int n = length(head);
    if (k > n)
        return head;
    if (2 * k - 1 == n)
        return head;

    struct Node *prevX = NULL, *x = head;
    for (int i = 1; i < k; i++)
    {
        prevX = x;
        x = x->next;
    }

    struct Node *prevY = NULL, *y = head;
    for (int i = 1; i < n - k + 1; i++)
    {
        prevY = y;
        y = y->next;
    }

    if (prevX)
        prevX->next = y;
    else
        head = y;

    if (prevY)
        prevY->next = x;
    else
        head = x;

    struct Node *temp = x->next;
    x->next = y->next;
    y->next = temp;

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
    int n, k, x;
    struct Node *head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insert(head, x);
    }
    scanf("%d", &k);
    head = swapK(head, k);
    print(head);
    return 0;
}
