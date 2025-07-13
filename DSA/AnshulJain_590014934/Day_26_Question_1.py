class ListNode:
    def __init__(self, val=0, next=None): self.val, self.next = val, next
def build(values):
    dummy = ListNode(0)
    curr = dummy
    for v in values:
        curr.next = ListNode(v)
        curr = curr.next
    return dummy.next
def print_list(head):
    while head:
        print(head.val, end=" -> " if head.next else "\n")
        head = head.next
def swap_kth(head, k):
    n, cur = 0, head
    while cur: n, cur = n + 1, cur.next
    if k > n or 2 * k - 1 == n: return head
    dummy = ListNode(0, head)
    prev1, prev2 = dummy, dummy
    for _ in range(k - 1): prev1 = prev1.next
    for _ in range(n - k): prev2 = prev2.next
    node1, node2 = prev1.next, prev2.next
    if prev1.next == prev2:  # adjacent nodes
        prev1.next, node1.next, node2.next = node2, node2.next, node1
    elif prev2.next == prev1:
        prev2.next, node2.next, node1.next = node1, node1.next, node2
    else:
        prev1.next, prev2.next = node2, node1
        node1.next, node2.next = node2.next, node1.next
    return dummy.next
vals = list(map(int, input().split()))#TAking input from the user
k = int(input())
head = build(vals)
head = swap_kth(head, k)
print_list(head)
# Example input: 1 2 3 4 5
# k = 2    
#output: 1 -> 4 -> 3 -> 2 -> 5