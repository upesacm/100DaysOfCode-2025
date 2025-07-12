# 3. Remove every k'th node
# A problem that teaches interval-based node deletion and demonstrates how to remove nodes following a specific pattern while maintaining list structure.

# Given a singly linked list, your task is to remove every kth node from the linked list. This operation is commonly used in data sampling and periodic filtering applications where you need to eliminate elements at regular intervals for data reduction or pattern-based processing. The challenge involves maintaining proper node connections while counting positions and handling the deletion pattern throughout the entire list.

# This teaches interval-based deletion and pattern-based traversal techniques that are essential for data filtering and systematic element removal operations.

# Your task: Remove every kth node from a linked list while maintaining proper connections and handling edge cases.

# Examples
# Input:

# Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8, k = 2
# Output:

# 1 -> 3 -> 5 -> 7
# Input:

# Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10, k = 3
# Output:

# 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def removeEveryKthNode(head: ListNode, k: int) -> ListNode:
    if k == 1:
        return None  # Remove every node

    current = head
    prev = None
    count = 1

    while current:
        if count % k == 0:
            # Remove current node
            if prev:
                prev.next = current.next
            # We don't move prev forward here
        else:
            prev = current
        current = current.next
        count += 1

    return head
