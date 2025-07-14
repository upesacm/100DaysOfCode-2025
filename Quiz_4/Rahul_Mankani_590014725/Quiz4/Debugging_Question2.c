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
    if (newNode == NULL) 
    {
        exit(1); // Handle memory allocation failure
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
int findKthFromEnd(struct ListNode* head, int k) 
{
    if (head == NULL || k <= 0) 
    {
        return -1;
    }
    struct ListNode* first = head;
    struct ListNode* second = head;
    // Advance first pointer k steps
    for (int i = 0; i < k; i++) 
    {
        if (first == NULL) 
        {
            return -1; // List is shorter than k
        }
        first = first->next;
    }
    // Move both pointers until first reaches the end
    while (first != NULL) 
    {
        first = first->next;
        second = second->next;
    }
    // Check if second is valid
    if (second == NULL) 
    {
        return -1;
    }
    return second->val;
}
void freeList(struct ListNode* head) 
{
    struct ListNode* current = head;
    while (current != NULL) 
    {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}
void printList(struct ListNode* head) 
{
    struct ListNode* current = head;
    while (current != NULL) 
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}
int main() 
{
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    printf("Original list: ");
    printList(head);
    int k = 2;
    int result = findKthFromEnd(head, k);
    if (result != -1) 
    {
        printf("The %dth node from the end is: %d\n", k, result);
    } 
    else 
    {
        printf("Invalid k or empty list\n");
    }
    // Free the list to prevent memory leaks
    freeList(head);
    return 0;
}
