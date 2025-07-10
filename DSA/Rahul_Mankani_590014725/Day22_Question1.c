#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int value;
    struct Node* next;
};
struct Node* newNode(int value) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    return node;
}
struct Node* findMiddle(struct Node* start) 
{
    if (start == NULL || start->next == NULL) 
    {
        return start;
    }
    struct Node* slow = start;
    struct Node* fast = start;
    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void printList(struct Node* start) 
{
    struct Node* temp = start;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() 
{
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    printf("Original Linked List: ");
    printList(head);
    struct Node* middle = findMiddle(head);
    if (middle != NULL) 
    {
        printf("Middle node value: %d\n", middle->value);
    }
    head->next->next->next->next->next = newNode(6);
    printf("\nUpdated Linked List: ");
    printList(head);
    middle = findMiddle(head);
    if (middle != NULL) 
    {
        printf("Middle node value: %d\n", middle->value);
    }
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) 
    {
        next = current->next;
        free(current);
        current = next;
    }
    return 0;
}
