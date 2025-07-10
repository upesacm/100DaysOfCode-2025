# 2. Intersection Sorted Linked Lists
# A problem that demonstrates merge-like operations on sorted data structures and teaches how to find common elements efficiently between two sorted lists.

# Given that two linked lists are sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made without changing the original lists. The elements of the linked list are not necessarily distinct. This operation is fundamental in data analysis and set operations where you need to find common elements between sorted datasets efficiently without modifying the original data structures.

# This introduces merge-based intersection and sorted data processing techniques that are crucial for database operations and efficient set computations.

# Your task: Find intersection of two sorted linked lists by creating a new list while preserving original lists.

# Examples
# Input:

# LinkedList1 = 1->2->3->4->6, LinkedList2 = 2->4->6->8
# Output:

# 2->4->6
# Input:

# LinkedList1 = 10->20->40->50, LinkedList2 = 15->40
# Output:

# 40
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def intersectLists(head1: ListNode, head2: ListNode) -> ListNode:
    dummy = ListNode(-1)  # Dummy node to form the result list
    tail = dummy
    ptr1 = head1
    ptr2 = head2
    while ptr1 and ptr2:
        if ptr1.val == ptr2.val:
            # Add common node value to result
            tail.next = ListNode(ptr1.val)
            tail = tail.next
            ptr1 = ptr1.next
            ptr2 = ptr2.next
        elif ptr1.val < ptr2.val:
            ptr1 = ptr1.next
        else:
            ptr2 = ptr2.next
    return dummy.next  # Skip dummy node
