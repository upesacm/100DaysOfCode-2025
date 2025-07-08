# 2. Delete N nodes after M nodes of a linked list
# A problem that demonstrates pattern-based linked list modification and teaches how to delete nodes following specific intervals and patterns.

# Given a linked list, delete n nodes after skipping m nodes of a linked list until the last of the linked list. This operation is commonly used in data filtering and pattern-based processing applications where you need to remove elements at regular intervals while preserving specific sections. The challenge involves understanding how to maintain proper node connections while following a deletion pattern throughout the entire list.

# This introduces pattern-based traversal and conditional node deletion techniques that are crucial for data stream processing and interval-based operations.

# Your task: Delete nodes following a specific pattern while maintaining proper list connections and handling edge cases.

# Examples
# Input:

# Linked List: 9->1->3->5->9->4->10->1, n = 1, m = 2
# Output:

# 9->1->5->9->10->1
# Input:

# Linked List: 1->2->3->4->5->6, n = 1, m = 6
# Output:

# 1->2->3->4->5->6

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def delete_n_after_m(head, n, m):
    current = head
    while current:
        # Skip m nodes
        for _ in range(1, m):
            if not current:
                return head
            current = current.next
        if not current:
            break

        # Start deleting next n nodes
        temp = current.next
        for _ in range(n):
            if not temp:
                break
            temp = temp.next

        # Connect the m-th node to the node after the n deleted nodes
        current.next = temp
        current = temp
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