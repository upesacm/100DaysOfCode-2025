#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* newNode(int val) 
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* findMiddle(struct ListNode* head) 
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct ListNode* reverseList(struct ListNode* head) 
{
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;
    while (current != NULL) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        return true;
    }
    
    struct ListNode* middle = findMiddle(head);
    
    struct ListNode* secondHalf = reverseList(middle);
    struct ListNode* firstHalf = head;
    
    bool result = true;
    struct ListNode* temp1 = firstHalf;
    struct ListNode* temp2 = secondHalf;
    while (temp2 != NULL) 
    {
        if (temp1->val != temp2->val) 
        {
            result = false;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    reverseList(secondHalf);
    
    return result;
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
    int n;
    printf("Enter the size of the linked list (must be > 0): ");
    scanf("%d", &n);
    
    if (n <= 0) 
    {
        printf("Invalid size. Size must be greater than 0.\n");
        return 1;
    }
    
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    
    printf("Enter the elements of the linked list (elements must be != 0): ");
    for (int i = 0; i < n; i++) 
    {
        int val;
        scanf("%d", &val);
        if (val == 0) 
        {
            printf("Elements must be positive integers (non-zero).\n");
            freeList(head);
            return 1;
        }
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
    
    bool result = isPalindrome(head);
    printf(result ? "true\n" : "false\n");
    
    freeList(head);
    return 0;
}