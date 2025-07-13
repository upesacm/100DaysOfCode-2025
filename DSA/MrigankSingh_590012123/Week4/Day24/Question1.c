#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* Reverse(struct ListNode* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        return head;
    }
    
    struct ListNode* new_head = Reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return new_head;
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
    int n;
    scanf("%d", &n);
    if (n <= 0) 
    {
        printf("\n");
        return 0;
    }
    
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    
    for (int i = 0; i < n; i++) 
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
    
    head = Reverse(head);
    
    Print(head);
    Free(head);
    return 0;
}