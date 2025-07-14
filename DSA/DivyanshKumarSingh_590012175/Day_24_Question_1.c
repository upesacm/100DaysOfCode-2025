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
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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
    printf(" -> NULL\n");
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
    head = reverse(head);
    print(head);
    return 0;
}
