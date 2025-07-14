#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

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

struct Node *makeUnion(struct Node *h1, struct Node *h2)
{
    int a[1000], n = 0;
    while (h1)
    {
        a[n++] = h1->data;
        h1 = h1->next;
    }
    while (h2)
    {
        a[n++] = h2->data;
        h2 = h2->next;
    }

    qsort(a, n, sizeof(int), cmp);

    struct Node *res = NULL;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || a[i] != a[i - 1])
            res = insert(res, a[i]);
    }
    return res;
}

int main()
{
    int n1, n2, x;
    struct Node *h1 = NULL, *h2 = NULL;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &x);
        h1 = insert(h1, x);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &x);
        h2 = insert(h2, x);
    }
    struct Node *res = makeUnion(h1, h2);
    print(res);
    return 0;
}
