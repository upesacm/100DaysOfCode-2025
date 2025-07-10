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
int countOccurrences(struct ListNode* head, int key) 
{
    int count = 0;
    struct ListNode* current = head;
    while (current != NULL) 
    {
        if (current->val == key) 
        {
            count++;
        }
        current = current->next;
    }
    return count;
}
int main() 
{
    struct ListNode* head = createLinkedList();
    
    if (head == NULL) 
    {
        printf("The list is empty.\n");
        return 0;
    }
    int key;
    printf("Enter the key to count: ");
    scanf("%d", &key);
    int result = countOccurrences(head, key);
    printf("The key %d appears %d times in the list.\n", key, result);
    struct ListNode* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
