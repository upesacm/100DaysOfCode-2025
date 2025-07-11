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

void printList(struct ListNode* head) 
{
    struct ListNode* temp = head;
    while (temp != NULL) 
    {
        printf("%d", temp->val);
        if (temp->next != NULL) 
        {
            printf("->");
        }
        temp = temp->next;
    }
    printf("\n");
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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode* dummyHead = newNode(0);
    struct ListNode* current = dummyHead;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) 
    {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        current->next = newNode(sum % 10);
        current = current->next;
        
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    
    struct ListNode* result = dummyHead->next;
    free(dummyHead);
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
    int n1, n2;
    
    printf("Enter the size of the first linked list (must be > 0): ");
    scanf("%d", &n1);
    
    if (n1 <= 0) 
    {
        printf("Invalid size. Size must be greater than 0.\n");
        return 1;
    }
    
    struct ListNode* head1 = NULL;
    struct ListNode* tail1 = NULL;
    
    printf("Enter the elements of the first linked list (digits 0-9): ");
    for (int i = 0; i < n1; i++) 
    {
        int val;
        scanf("%d", &val);
        if (val < 0 || val > 9) 
        {
            printf("Elements must be digits between 0 and 9.\n");
            freeList(head1);
            return 1;
        }
        struct ListNode* node = newNode(val);
        if (head1 == NULL) 
        {
            head1 = node;
            tail1 = node;
        } 
        else 
        {
            tail1->next = node;
            tail1 = node;
        }
    }
    
    printf("Enter the size of the second linked list (must be > 0): ");
    scanf("%d", &n2);
    
    if (n2 <= 0) 
    {
        printf("Invalid size. Size must be greater than 0.\n");
        freeList(head1);
        return 1;
    }
    
    struct ListNode* head2 = NULL;
    struct ListNode* tail2 = NULL;
    
    printf("Enter the elements of the second linked list (digits 0-9): ");
    for (int i = 0; i < n2; i++) 
    {
        int val;
        scanf("%d", &val);
        if (val < 0 || val > 9) 
        {
            printf("Elements must be digits between 0 and 9.\n");
            freeList(head1);
            freeList(head2);
            return 1;
        }
        struct ListNode* node = newNode(val);
        if (head2 == NULL) 
        {
            head2 = node;
            tail2 = node;
        } 
        else 
        {
            tail2->next = node;
            tail2 = node;
        }
    }
    
    head1 = reverseList(head1);
    head2 = reverseList(head2);
    
    struct ListNode* sum = addTwoNumbers(head1, head2);
    
    sum = reverseList(sum);
    
    while (sum != NULL && sum->val == 0 && sum->next != NULL) 
    {
        struct ListNode* temp = sum;
        sum = sum->next;
        free(temp);
    }
    
    printf("Sum of the two numbers: ");
    printList(sum);
    
    freeList(head1);
    freeList(head2);
    freeList(sum);
    
    return 0;
}