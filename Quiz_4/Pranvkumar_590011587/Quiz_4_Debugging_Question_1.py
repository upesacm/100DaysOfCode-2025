"""
Original C Code (with bugs):

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

struct ListNode* removeDuplicates(struct ListNode* head)
{
    if (head = NULL)               //  BUG: should be '==', not '='
    {  
        return head;
    }

    struct ListNode* current = head;
    while (current->next != NULL)
    {
        if (current->val == current->next->val)
        {
            struct ListNode* duplicate = current->next;
            current->next = current->next->next;
            free(duplicate);
        }
        else
        {
            current = current->next;   //  Only advance if no duplicate
        }
    }
    return head;
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
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);
 
    printf("Original list: ");
    printList(head);
     
    head = removeDuplicates(head);

    printf("After removing duplicates: ");
    printList(head);
    return 0;
}

Q1. What is the bug in the condition if (head = NULL)?
=> It is using assignment '=' instead of comparison '=='. The correct check is:
   if (head == NULL)

Q2. Why is current = current->next; placed only inside the else block?
=> Because when a duplicate is removed, the `current` node should remain the same
   to check for more duplicates. Only move to next when values are not equal.

Q3. Debugged Python Version Below:
"""

# Python  code
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def create_node(val):
    return ListNode(val)
def remove_duplicates(head):
    if head is None:
        return head
    current = head
    while current and current.next:
        if current.val == current.next.val:
            duplicate = current.next
            current.next = current.next.next
            del duplicate  
        else:
            current = current.next
    return head

def print_list(head):
    current = head
    while current:
        print(current.val, end=" ")
        current = current.next
    print()

if __name__ == "__main__":
    head = create_node(1)
    head.next = create_node(1)
    head.next.next = create_node(2)
    head.next.next.next = create_node(3)
    head.next.next.next.next = create_node(3)

    print("Original list:")
    print_list(head)

    head = remove_duplicates(head)

    print("After removing duplicates:")
    print_list(head)