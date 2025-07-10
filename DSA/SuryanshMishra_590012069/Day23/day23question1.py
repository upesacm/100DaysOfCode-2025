# 1. Kth from End of Linked List
# A problem that introduces advanced linked list traversal techniques and teaches how to find elements from the end efficiently using the two-pointer approach.

# Given the head of a linked list and the number k, your task is to find the kth node from the end. If k is more than the number of nodes, then the output should be -1. This problem appears frequently in interviews and real-world applications like implementing undo operations, recent history tracking, or buffer management systems. You can solve this by first counting nodes and then traversing again, but try to think of more efficient approaches using the two-pointer technique that requires only one pass.

# This teaches two-pointer traversal and reverse indexing techniques that are essential for efficient linked list processing and single-pass algorithms.

# Your task: Find the kth node from the end of a linked list using efficient single-pass traversal techniques.

# Examples
# Input:

# LinkedList: 1->2->3->4->5->6->7->8->9, k = 2
# Output:

# 8
# Input:

# LinkedList: 10->5->100->5, k = 5
# Output:

# -1

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def kth_from_end(head, k):
    fast = slow = head
    # Move fast pointer k steps ahead
    for _ in range(k):
        if not fast:
            return -1
        fast = fast.next
    # Move both pointers until fast reaches the end
    while fast:
        slow = slow.next
        fast = fast.next
    return slow.val if slow else -1

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