# 1. Delete in a Doubly Linked List
# A problem that introduces doubly linked list manipulation techniques and teaches how to delete nodes while maintaining bidirectional pointer connections.

# Given a Doubly Linked list and a position, the task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly linked list. This problem appears frequently in interviews and real-world applications like implementing browser history navigation, undo-redo operations, or music playlist management. The challenge involves properly handling both forward and backward pointers while maintaining list integrity and managing edge cases like deleting the head or tail node.

# This teaches bidirectional pointer manipulation and doubly linked list operations that are essential for complex data structure management and efficient two-way navigation systems.

# Your task: Delete a node at a specific position in a doubly linked list while maintaining proper forward and backward connections.

# Examples
# Input:

# LinkedList = 1 <--> 3 <--> 4, x = 3
# Output:

# 1 <--> 3
# Input:

# LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
# Output:

# 5 <--> 2 <--> 9
class DoublyNode:
    def __init__(self, val=0):
        self.data = val
        self.next = None
        self.prev = None

def deleteNode(head: DoublyNode, x: int) -> DoublyNode:
    if not head:
        return None

    # If the head is to be deleted
    if x == 1:
        new_head = head.next
        if new_head:
            new_head.prev = None
        return new_head

    current = head
    count = 1

    while current and count < x:
        current = current.next
        count += 1

    if not current:
        return head  # Position out of bounds

    # Update pointers
    if current.prev:
        current.prev.next = current.next
    if current.next:
        current.next.prev = current.prev

    return head
