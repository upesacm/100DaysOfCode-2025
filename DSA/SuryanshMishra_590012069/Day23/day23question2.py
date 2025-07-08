# 2. Remove Duplicates from a Sorted Linked List
# A problem that demonstrates linked list modification techniques and teaches how to remove duplicate elements while maintaining list integrity.

# Given a singly linked list that is already sorted, the task is to remove duplicates (nodes with duplicate values) from the given list if they exist. This operation is fundamental in data cleaning and deduplication applications where you need to eliminate redundant entries while preserving the original order. The challenge involves understanding how to properly link nodes while skipping duplicates and managing memory efficiently.

# This introduces linked list modification and duplicate removal techniques that are crucial for data preprocessing and memory-efficient list operations.

# Your task: Remove duplicate nodes from a sorted linked list while maintaining proper node connections.

# Examples
# Input:

# LinkedList: 2->2->4->5
# Output:

# 2 -> 4 -> 5
# Input:

# LinkedList: 2->2->2->2->2
# Output:

# 2

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def remove_duplicates(head):
    current = head
    while current and current.next:
        if current.val == current.next.val:
            current.next = current.next.next  # Skip duplicate
        else:
            current = current.next
    return head

# Helper to build a linked list from a list
def build_linked_list(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    curr = head
    for val in arr[1:]:
        curr.next = ListNode(val)
        curr = curr.next
    return head

# Helper to print linked list
def print_linked_list(head):
    curr = head
    while curr:
        print(curr.val, end=" ")
        curr = curr.next
    print()