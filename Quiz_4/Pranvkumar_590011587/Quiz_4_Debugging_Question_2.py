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

int findKthFromEnd(struct ListNode* head, int k)
{
    if (head == NULL || k <= 0)
    {
        return -1;
    }

    struct ListNode* first = head;
    struct ListNode* second = head;

    for (int i = 0; i <= k; i++)  // BUG: This should run k times, not k+1 times
    {  
        if (first == NULL)
        {
            return -1;  // Safe check to avoid overflow
        }
        first = first->next;
    }

    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    return second->val;  
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
        printf("The %dth node from end is: %d\n", k, result);
    }
    else
    {
        printf("Invalid k or empty list\n");
    }

    return 0;
}

 Task 1: Bug Fix
 The bug is in this loop:
   for (int i = 0; i <= k; i++)
   It runs **k+1 times**, which overshoots the pointer.
    Correct version:
   for (int i = 0; i < k; i++)

 Task 2: Is checking `first == NULL` inside the loop necessary?
 YES. It ensures that k is not larger than the length of the list.
   If you skip it, you may try to access `first->next` on a NULL pointer, causing a crash.

"""

#PYTHON IMPLEMENTATION

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def create_node(val):
    return ListNode(val)

def find_kth_from_end(head, k):
    if head is None or k <= 0:
        return -1
    first = head
    second = head
    for _ in range(k):  # Fixed: Only k steps
        if first is None:
            return -1  
        first = first.next
    while first:
        first = first.next
        second = second.next

    return second.val

def print_list(head):
    current = head
    while current:
        print(current.val, end=" ")
        current = current.next
    print()

if __name__ == "__main__":
    head = create_node(1)
    head.next = create_node(2)
    head.next.next = create_node(3)
    head.next.next.next = create_node(4)
    head.next.next.next.next = create_node(5)
    print("Original list:")
    print_list(head)
    k = 2
    result = find_kth_from_end(head, k)
    if result != -1:
        print(f"The {k}th node from end is: {result}")
    else:
        print("Invalid k or empty list")