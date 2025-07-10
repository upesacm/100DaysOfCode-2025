# 1. Palindrome Linked List
# A problem that introduces advanced linked list analysis techniques and teaches how to check symmetry in sequential data structures efficiently.

# Given a head singly linked list of positive integers, the task is to check if the given linked list is palindrome or not. A palindrome reads the same forwards and backwards. This problem appears frequently in interviews and real-world applications like data validation, symmetry detection in sequences, or implementing verification algorithms. You can solve this by converting to an array first, but try to think of more efficient approaches using techniques like reversing half the list or using two pointers with recursion.

# This teaches symmetry detection and two-pointer validation techniques that are essential for pattern recognition and efficient data structure analysis.

# Your task: Check if a linked list is a palindrome using efficient techniques without extra space or with minimal space complexity.

# Examples
# Input:

# head: 1 -> 2 -> 1 -> 1 -> 2 -> 1
# Output:

# true
# Input:

# head: 1 -> 2 -> 3 -> 4
# Output:

# false
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def isPalindrome(head: ListNode) -> bool:
    if not head or not head.next:
        return True

    # Step 1: Find the middle using slow and fast pointers
    slow = head
    fast = head
    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next

    # Step 2: Reverse the second half
    prev = None
    curr = slow
    while curr:
        next_node = curr.next
        curr.next = prev
        prev = curr
        curr = next_node
    second_half_head = prev

    # Step 3: Compare the first and second halves
    first = head
    second = second_half_head
    result = True
    while second:
        if first.val != second.val:
            result = False
            break
        first = first.next
        second = second.next

    # (Optional) Step 4: Restore the original list (not required here)
    # Reverse the second half back if needed

    return result

