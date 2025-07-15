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

struct Node *sort012(struct Node *head)
{
    struct Node *zeroH = NULL, *zeroT = NULL;
    struct Node *oneH = NULL, *oneT = NULL;
    struct Node *twoH = NULL, *twoT = NULL;

    struct Node *curr = head;
    while (curr)
    {
        struct Node *next = curr->next;
        curr->next = NULL;
        if (curr->data == 0)
        {
            if (!zeroH)
                zeroH = zeroT = curr;
            else
                zeroT = zeroT->next = curr;
        }
        else if (curr->data == 1)
        {
            if (!oneH)
                oneH = oneT = curr;
            else
                oneT = oneT->next = curr;
        }
        else
        {
            if (!twoH)
                twoH = twoT = curr;
            else
                twoT = twoT->next = curr;
        }
        curr = next;
    }

    if (zeroT)
        zeroT->next = oneH;
    else
        zeroH = oneH;

    if (oneT)
        oneT->next = twoH;
    else if (zeroT)
        zeroT->next = twoH;
    else if (!zeroH)
        zeroH = twoH;

    return zeroH;
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
    int n, x;
    struct Node *head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insert(head, x);
    }
    head = sort012(head);
    print(head);
    return 0;
}
