# 2. Union of Two Linked Lists
# A problem that demonstrates set operations on linked lists and teaches how to combine two lists while eliminating duplicates and maintaining sorted order.

# Given two linked lists (L1 & L2), your task is to complete the function makeUnion(), which returns the union list of two linked lists. This union list should include all the distinct elements only and it should be sorted in ascending order. This operation is fundamental in data merging and set operations where you need to combine datasets while removing duplicates and maintaining order. The challenge involves efficiently handling duplicates and sorting the final result.

# This introduces set union operations and duplicate elimination techniques that are crucial for data consolidation and efficient list merging operations.

# Your task: Create union of two linked lists with distinct elements in sorted order using efficient merging and deduplication.

# Examples
# Input:

# L1 = 9->6->4->2->3->8, L2 = 1->2->8->6->2
# Output:

# 1 -> 2 -> 3 -> 4 -> 6 -> 8 -> 9
# Input:

# L1 = 1->5->1->2->2->5, L2 = 4->5->6->7->1
# Output:

# 1 -> 2 -> 4 -> 5 -> 6 -> 7
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def makeUnion(head1: ListNode, head2: ListNode) -> ListNode:
    unique_vals = set()

    # Step 1: Collect values from both lists
    current = head1
    while current:
        unique_vals.add(current.val)
        current = current.next

    current = head2
    while current:
        unique_vals.add(current.val)
        current = current.next

    # Step 2: Sort the values
    sorted_vals = sorted(unique_vals)

    # Step 3: Create new sorted linked list
    dummy = ListNode(-1)
    current = dummy
    for val in sorted_vals:
        current.next = ListNode(val)
        current = current.next

    return dummy.next
