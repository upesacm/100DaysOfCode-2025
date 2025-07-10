#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* Delete_Position(struct ListNode* head, int x) {
    if (head == NULL || x <= 0) {
        return head;
    }

    if (x == 1) 
    {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct ListNode* current = head;
    int count = 1;

    while (current != NULL && count < x - 1) 
    {
        current = current->next;
        count++;
    }

    if (current == NULL || current->next == NULL) 
    {
        return head;
    }

    struct ListNode* temp = current->next;
    current->next = temp->next;
    free(temp);

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
    int size, x;
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

    scanf("%d", &x);
    head = Delete_Position(head, x);
    Print(head);
    Free(head);

    return 0;
}