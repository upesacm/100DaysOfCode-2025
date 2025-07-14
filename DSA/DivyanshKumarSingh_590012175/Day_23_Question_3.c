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

struct Node *deleteMid(struct Node *head)
{
    if (!head || !head->next)
    {
        free(head);
        return NULL;
    }
    struct Node *slow = head, *fast = head, *prev = NULL;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = slow->next;
    free(slow);
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
    int n, x;
    struct Node *head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insert(head, x);
    }
    head = deleteMid(head);
    if (!head)
        printf("NULL\n");
    else
        print(head);
    return 0;
}
