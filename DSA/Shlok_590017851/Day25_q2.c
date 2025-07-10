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
void insertAtTail(struct ListNode** head, struct ListNode** tail, int val)
{
    struct ListNode* newNode = createNode(val);
    if (*head == NULL) 
    {
        *head = *tail = newNode;
    } 
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}
struct ListNode* findIntersection(struct ListNode* head1, struct ListNode* head2) 
{
    struct ListNode* ptr1 = head1;
    struct ListNode* ptr2 = head2;
    struct ListNode* resultHead = NULL;
    struct ListNode* resultTail = NULL;

    while (ptr1 && ptr2) 
    {
        if (ptr1->val == ptr2->val)
        {
            insertAtTail(&resultHead, &resultTail, ptr1->val);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } 
        else if (ptr1->val < ptr2->val) 
        {
            ptr1 = ptr1->next;
        } 
        else 
        {
            ptr2 = ptr2->next;
        }
    }
    return resultHead;
}
void printList(struct ListNode* head)
{
    while (head)
      {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}
int main() 
{
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(3);
    list1->next->next->next = createNode(4);
    list1->next->next->next->next = createNode(6);

    struct ListNode* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);
    list2->next->next->next = createNode(8);

    struct ListNode* result = findIntersection(list1, list2);

    printf("Intersection: ");
    printList(result); 
    return 0;
}
