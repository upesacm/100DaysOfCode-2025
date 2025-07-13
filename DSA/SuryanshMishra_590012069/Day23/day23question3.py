# 3. Delete Middle of Linked List
# A problem that teaches linked list deletion techniques and demonstrates how to remove specific nodes while maintaining list structure.

# Given a singly linked list, delete the middle of the linked list. If there are even nodes, then there would be two middle nodes, and we need to delete the second middle element. If the input linked list has a single node, then it should return NULL. This problem is commonly used in memory management and list optimization where you need to remove elements based on position while maintaining list integrity.

# This teaches node deletion techniques and position-based removal that are essential for dynamic list management and memory optimization.

# Your task: Delete the middle node of a linked list while properly handling edge cases and maintaining list connections.

# Examples
# Input:

# LinkedList: 1->2->3->4->5
# Output:

# 1->2->4->5
# Input:

# LinkedList: 2->4->6->7->5->1
# Output:

# 2->4->6->5->1
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def delete_middle(head):
    if not head or not head.next:
        return None  # If there's 0 or 1 node, return None

    slow = head
    fast = head
    prev = None

    while fast and fast.next:
        fast = fast.next.next
        prev = slow
        slow = slow.next

    # Remove the middle node
    prev.next = slow.next
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