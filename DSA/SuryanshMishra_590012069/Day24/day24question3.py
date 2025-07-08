# 3. Delete in a Singly Linked List
# A problem that teaches position-based node deletion and demonstrates how to remove specific nodes by their index while maintaining list integrity.

# Given a singly linked list and an integer x, delete the xth node (1-based indexing) from the singly linked list. This operation is fundamental in dynamic data management and position-based removal applications where you need to delete elements at specific positions efficiently. The challenge involves understanding how to traverse to the correct position, handle edge cases like deleting the head node, and properly reconnect the remaining nodes.

# This teaches position-based deletion and index-based traversal techniques that are essential for dynamic list management and efficient element removal.

# Your task: Delete a node at a specific position while properly handling edge cases and maintaining list connections.

# Examples
# Input:

# Linked list: 1 -> 3 -> 4, x = 3
# Output:

# 1 -> 3
# Input:

# Linked list: 1 -> 5 -> 2 -> 9, x = 2
# Output:

# 1 -> 2 -> 9

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def delete_at_position(head, x):
    if not head:
        return None
    if x == 1:
        return head.next  # Delete head node

    current = head
    count = 1
    while current and count < x - 1:
        current = current.next
        count += 1

    # If current is None or next is None, position is out of bounds
    if not current or not current.next:
        return head

    current.next = current.next.next
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