# 3. Sort a linked list of 0s, 1s and 2s
# A problem that teaches specialized sorting techniques and demonstrates how to rearrange linked lists with limited value domains efficiently.

# Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only, your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end. This is a variation of the Dutch National Flag problem applied to linked lists and is commonly used in data preprocessing and categorical sorting applications. You can solve this by counting occurrences first, but try to think of more efficient approaches using three-pointer technique or node rearrangement.

# This teaches categorical sorting and three-way partitioning techniques that are essential for specialized sorting algorithms and efficient data categorization.

# Your task: Sort a linked list containing only 0s, 1s, and 2s using efficient partitioning techniques without extra space.

# Examples
# Input:

# head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
# Output:

# 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2
# Input:

# head = 2 → 2 → 0 → 1
# Output:

# 0 → 1 → 2 → 2
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def sort012List(head: ListNode) -> ListNode:
    if not head or not head.next:
        return head

    # Create dummy heads and tails for 0s, 1s, 2s
    zero_head = zero_tail = ListNode(-1)
    one_head = one_tail = ListNode(-1)
    two_head = two_tail = ListNode(-1)

    # Distribute nodes into three lists
    current = head
    while current:
        if current.val == 0:
            zero_tail.next = current
            zero_tail = zero_tail.next
        elif current.val == 1:
            one_tail.next = current
            one_tail = one_tail.next
        else:
            two_tail.next = current
            two_tail = two_tail.next
        current = current.next

    # Connect the three lists
    zero_tail.next = one_head.next if one_head.next else two_head.next
    one_tail.next = two_head.next
    two_tail.next = None  # Mark end of list

    # New head is start of 0s if available, else 1s or 2s
    return zero_head.next if zero_head.next else one_head.next if one_head.next else two_head.next
