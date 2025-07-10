#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* Delete(struct ListNode* head, int m, int n) 
{
    if (head == NULL || m <= 0 || n < 0) 
    {
        return head;
    }

    struct ListNode *current = head;
    struct ListNode *prev = NULL;

    while (current != NULL) 
    {
        for (int i = 0; i < m && current != NULL; i++) 
        {
            prev = current;
            current = current->next;
        }

        for (int i = 0; i < n && current != NULL; i++) 
        {
            struct ListNode *temp = current;
            current = current->next;
            free(temp);
        }

        if (prev != NULL) 
        {
            prev->next = current;
        }
    }

    return head;
}

struct ListNode* New(int val) 
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void Print(struct ListNode* head) 
{
    struct ListNode* current = head;
    while (current != NULL) 
    {
        printf("%d", current->val);
        if (current->next != NULL) 
        {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

void Free(struct ListNode* head) 
{
    struct ListNode* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() 
{
    int size, m, n;
    scanf("%d", &size);
    if (size <= 0) 
    {
        printf("\n");
        return 0;
    }

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    for (int i = 0; i < size; i++) 
    {
        int val;
        scanf("%d", &val);
        struct ListNode* node = New(val);
        if (head == NULL) 
        {
            head = node;
            tail = node;
        } 
        else 
        {
            tail->next = node;
            tail = node;
        }
    }

    scanf("%d %d", &m, &n);
    head = Delete(head, m, n);
    Print(head);
    Free(head);

    return 0;
}