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
    struct Node *curr = head;
    while (curr)
    {
        struct Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int isPalindrome(struct Node *head)
{
    if (!head || !head->next)
        return 1;
    struct Node *slow = head, *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct Node *second = reverse(slow->next);
    struct Node *first = head;
    while (second)
    {
        if (first->data != second->data)
            return 0;
        first = first->next;
        second = second->next;
    }
    return 1;
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
    if (isPalindrome(head))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
