#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode 
{
    int val;
    struct ListNode* next;
};
struct ListNode* reverseList(struct ListNode* head) 
{
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr) 
    {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(struct ListNode* head)
{
    if (head == NULL || head->next == NULL) return true;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* secondHalf = reverseList(slow);

    struct ListNode* firstHalf = head;
    struct ListNode* temp = secondHalf;  
    while (secondHalf) 
    {
        if (firstHalf->val != secondHalf->val)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}
struct ListNode* createNode(int val) 
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
void printList(struct ListNode* head) 
{
    while (head) 
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
int main()
{
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(1);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(2);
    head->next->next->next->next->next = createNode(1);

    if (isPalindrome(head))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
