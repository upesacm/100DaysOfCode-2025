#include <stdio.h>
#include <stdlib.h>
struct ListNode 
{
    int val;
    struct ListNode* next;
};
struct ListNode* createNode(int val) 
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
struct ListNode* createLinkedList() 
{
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n == 0) return NULL;
    printf("Enter element 1: ");
    scanf("%d", &val);
    struct ListNode* head = createNode(val);
    struct ListNode* current = head;
    for (int i = 2; i <= n; i++) 
    {
        printf("Enter element %d: ", i);
        scanf("%d", &val);
        current->next = createNode(val);
        current = current->next;
    }
    return head;
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
int main() 
{
    struct ListNode* head = createLinkedList();
    if (head == NULL) 
    {
        printf("The list is empty.\n");
        return 0;
    }
    struct ListNode* middle = findMiddle(head);
    printf("The middle node is: %d\n", middle->val);
    struct ListNode* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
