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

struct Node *reverse(struct Node *head)
{
    struct Node *prev = NULL;
    while (head)
    {
        struct Node *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

struct Node *addLists(struct Node *h1, struct Node *h2)
{
    h1 = reverse(h1);
    h2 = reverse(h2);
    struct Node *res = NULL;
    int carry = 0;
    while (h1 || h2 || carry)
    {
        int sum = carry;
        if (h1)
        {
            sum += h1->data;
            h1 = h1->next;
        }
        if (h2)
        {
            sum += h2->data;
            h2 = h2->next;
        }
        carry = sum / 10;
        struct Node *temp = malloc(sizeof(struct Node));
        temp->data = sum % 10;
        temp->next = res;
        res = temp;
    }
    return res;
}

void print(struct Node *head)
{
    while (head && head->data == 0)
        head = head->next;
    if (!head)
        printf("0\n");
    else
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
    struct Node *sum = addLists(head1, head2);
    print(sum);
    return 0;
}
