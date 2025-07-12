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

struct ListNode* findIntersection(struct ListNode* head1, struct ListNode* head2) 
{
    struct ListNode* resultHead = NULL;
    struct ListNode* resultTail = NULL;
    
    while (head1 != NULL && head2 != NULL) 
    {
        if (head1->val == head2->val) 
        {
            if (resultHead == NULL) 
            {
                resultHead = newNode(head1->val);
                resultTail = resultHead;
            } 
            else 
            {
                resultTail->next = newNode(head1->val);
                resultTail = resultTail->next;
            }
            head1 = head1->next;
            head2 = head2->next;
        } 
        else if (head1->val < head2->val) 
        {
            head1 = head1->next;
        } 
        else 
        {
            head2 = head2->next;
        }
    }
    
    return resultHead;
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
    
    printf("Enter the elements of the first linked list (elements must be != 0): ");
    for (int i = 0; i < n1; i++) 
    {
        int val;
        scanf("%d", &val);
        if (val == 0) 
        {
            printf("Elements must be positive integers (non-zero).\n");
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
    
    printf("Enter the elements of the second linked list (elements must be != 0): ");
    for (int i = 0; i < n2; i++) 
    {
        int val;
        scanf("%d", &val);
        if (val == 0) 
        {
            printf("Elements must be positive integers (non-zero).\n");
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
    
    struct ListNode* intersection = findIntersection(head1, head2);
    printf("Intersection of the two linked lists: ");
    printList(intersection);
    
    freeList(head1);
    freeList(head2);
    freeList(intersection);
    
    return 0;
}