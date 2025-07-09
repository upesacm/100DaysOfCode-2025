# 1. Reverse a Linked List
# A problem that introduces fundamental linked list manipulation techniques and teaches how to reverse the direction of node connections efficiently.

# Given the head of a linked list, the task is to reverse this list and return the reversed head. This is one of the most fundamental operations in linked list manipulation and appears frequently in interviews and real-world applications like implementing undo functionality, reversing data streams, or processing data in reverse order. You can solve this iteratively by changing the links between nodes, or recursively by processing nodes from the end. Understanding pointer manipulation is crucial for this problem.

# This teaches pointer manipulation and iterative/recursive thinking techniques that are essential for advanced linked list operations and data structure transformations.

# Your task: Reverse the direction of a linked list by changing node connections using efficient pointer manipulation.

# Examples
# Input:

# head: 1 -> 2 -> 3 -> 4 -> NULL
# Output:

# head: 4 -> 3 -> 2 -> 1 -> NULL
# Input:

# head: 2 -> 7 -> 10 -> 9 -> 8 -> NULL
# Output:

# head: 8 -> 9 -> 10 -> 7 -> 2 -> NULL
# Input:

# head: 2 -> NULL
# Output:

# 2 -> NULL

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverse_linked_list(head):
    prev = None
    current = head
    while current:
        next_node = current.next  # Store next node
        current.next = prev       # Reverse the link
        prev = current            # Move prev forward
        current = next_node       # Move current forward
    return prev

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