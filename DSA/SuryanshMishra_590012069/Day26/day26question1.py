# 1. Swap Kth nodes from ends
# A problem that introduces advanced linked list manipulation techniques and teaches how to swap nodes at symmetric positions efficiently using pointer operations.

# Given a singly linked list and an integer k, you need to swap the kth node from the beginning and the kth node from the end of the linked list. Swap the nodes through the links, not by changing the content of the nodes. This problem appears frequently in interviews and real-world applications like implementing symmetric operations, data rearrangement, or palindrome creation algorithms. The challenge involves finding the correct nodes to swap and properly handling all the pointer connections without breaking the list structure.

# This teaches symmetric node manipulation and complex pointer operations that are essential for advanced linked list transformations and positional swapping algorithms.

# Your task: Swap nodes at symmetric positions by manipulating pointers while maintaining list integrity and handling edge cases.

# Examples
# Input:

# LinkedList: 1->2->3->4, k = 1
# Output:

# true
# Input:

# LinkedList: 1->2->3->4->5, k = 7
# Output:

# true
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def swapKthNodes(head: ListNode, k: int) -> ListNode:
    if not head:
        return head

    # Step 1: Count length
    length = 0
    curr = head
    while curr:
        length += 1
        curr = curr.next

    if k > length:
        return head  # k is out of bounds

    if 2 * k - 1 == length:
        return head  # Swapping the same node

    # Step 2: Find prev and current for both kth positions
    def getKthNode(pos):
        prev = None
        curr = head
        for _ in range(pos - 1):
            prev = curr
            curr = curr.next
        return prev, curr

    prev1, node1 = getKthNode(k)
    prev2, node2 = getKthNode(length - k + 1)

    # Step 3: If nodes are adjacent, handle carefully
    if node1 == node2:
        return head  # Same node, no need to swap

    # Adjust previous nodes' next pointers
    if prev1:
        prev1.next = node2
    else:
        head = node2

    if prev2:
        prev2.next = node1
    else:
        head = node1

    # Swap next pointers
    node1.next, node2.next = node2.next, node1.next

    return head
