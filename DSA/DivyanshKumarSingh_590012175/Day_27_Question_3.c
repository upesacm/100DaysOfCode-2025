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

struct Node *removeK(struct Node *head, int k)
{
    if (k == 1)
        return NULL;
    struct Node *curr = head;
    int count = 1;
    while (curr && curr->next)
    {
        if ((count + 1) % k == 0)
        {
            struct Node *temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }
        else
        {
            curr = curr->next;
        }
        count++;
    }
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
    int n, x, k;
    struct Node *head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insert(head, x);
    }
    scanf("%d", &k);
    head = removeK(head, k);
    print(head);
    return 0;
}
