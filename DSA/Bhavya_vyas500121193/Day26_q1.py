class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def swap_kth_nodes(head, k):
    if not head:
        return head

    # Step 1: Count the length
    length = 0
    current = head
    while current:
        length += 1
        current = current.next

    # Step 2: Check for invalid k
    if k > length:
        return head

    if 2 * k - 1 == length:
        # kth from start and kth from end are same
        return head

    # Step 3: Find kth node from start and its previous node
    prev1, node1 = None, head
    for _ in range(k - 1):
        prev1 = node1
        node1 = node1.next

    # Step 4: Find kth node from end and its previous node
    prev2, node2 = None, head
    for _ in range(length - k):
        prev2 = node2
        node2 = node2.next

    # Step 5: If node1 or node2 is head, update head
    if prev1:
        prev1.next = node2
    else:
        head = node2

    if prev2:
        prev2.next = node1
    else:
        head = node1

    # Step 6: Swap next pointers
    node1.next, node2.next = node2.next, node1.next

    return head

# Helper to print list
def print_list(head):
    while head:
        print(head.val, end=" -> " if head.next else "\n")
        head = head.next

# Example
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
k = 1
new_head = swap_kth_nodes(head, k)
print_list(new_head)
