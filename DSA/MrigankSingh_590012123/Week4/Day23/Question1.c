#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

int Kth(struct ListNode* head, int k) 
{
    if (head == NULL || k <= 0) 
    {
        return -1;
    }
    
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    
    for (int i = 0; i < k; i++) 
    {
        if (fast == NULL) 
        {
            return -1;
        }
        fast = fast->next;
    }
    
    while (fast != NULL) 
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow->val;
}

struct ListNode* newNode(int val) 
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void freeList(struct ListNode* head) 
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
    int n, k;
    scanf("%d", &n);
    if (n <= 0) 
    {
        printf("-1\n");
        return 0;
    }
    
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    
    for (int i = 0; i < n; i++) 
    {
        int val;
        scanf("%d", &val);
        struct ListNode* node = newNode(val);
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
    
    scanf("%d", &k);
    int result = Kth(head, k);
    printf("%d\n", result);
    
    freeList(head);
    return 0;
}