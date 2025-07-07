#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertEnd(struct Node *head, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (!head)
        return newNode;

    struct Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;

    return head;
}

void findMiddle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow)
        printf("Middle element: %d\n", slow->data);
}

int main()
{
    struct Node *head = NULL;
    int n, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }

    findMiddle(head);
    return 0;
}
