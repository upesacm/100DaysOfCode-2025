Your task: Find the middle node of a linked list using efficient traversal techniques without 
multiple passes.

class ListNode:
    def __init__(self, value=0, next=None):
        self.value = value
        self.next = next

def find_middle_node(head):
    slow = fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    return slow
