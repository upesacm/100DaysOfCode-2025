# 2. Reverse a Doubly Linked List
# A problem that demonstrates advanced linked list reversal techniques and teaches how to reverse bidirectional connections efficiently.

# Given a doubly linked list, your task is to reverse the doubly linked list and return its head. This operation is fundamental in data structure manipulation and navigation systems where you need to change the direction of traversal while maintaining both forward and backward connectivity. The challenge involves swapping both the next and previous pointers for each node, which is more complex than reversing a singly linked list.

# This introduces bidirectional reversal and pointer swapping techniques that are crucial for advanced data structure transformations and efficient navigation system implementations.

# Your task: Reverse a doubly linked list by swapping both forward and backward pointers for all nodes.

# Examples
# Input:

# LinkedList: 3 <-> 4 <-> 5
# Output:

# 5 <-> 4 <-> 3
# Input:

# LinkedList: 75 <-> 122 <-> 59 <-> 196
# Output:

# 196 <-> 59 <-> 122 <-> 75
class DoublyNode:
    def __init__(self, val=0):
        self.data = val
        self.next = None
        self.prev = None

def reverseDoublyList(head: DoublyNode) -> DoublyNode:
    if not head or not head.next:
        return head  # Empty or single-node list

    current = head
    prev_node = None

    while current:
        # Swap next and prev
        current.prev, current.next = current.next, current.prev
        # Move prev_node to current
        prev_node = current
        # Move to next node (originally current.next, now current.prev after swap)
        current = current.prev

    # prev_node is the new head after full reversal
    return prev_node