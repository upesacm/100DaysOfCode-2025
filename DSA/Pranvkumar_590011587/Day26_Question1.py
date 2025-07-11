class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
def printList(head):
    while head:
        print(head.data, end=" -> " if head.next else "")
        head = head.next
    print()
def buildList(arr):
    if not arr:
        return None
    head = Node(arr[0])
    curr = head
    for val in arr[1:]:
        curr.next = Node(val)
        curr = curr.next
    return head
# 1. Swap Kth Node from Ends
def swapKth(head, k):
    n = 0
    curr = head
    while curr:
        n += 1
        curr = curr.next
    if k > n or 2*k - 1 == n:
        return head
    x = head
    x_prev = None
    for _ in range(k - 1):
        x_prev = x
        x = x.next
    y = head
    y_prev = None
    for _ in range(n - k):
        y_prev = y
        y = y.next
    if x_prev:
        x_prev.next = y
    else:
        head = y
    if y_prev:
        y_prev.next = x
    else:
        head = x
    x.next, y.next = y.next, x.next
    return head
# Example 1: 1->2->3->4, k = 1
list = buildList([1, 2, 3, 4])
result1 = swapKth(list, 1)
print("Input: 1->2->3->4, k=1\nOutput: ", end="")
printList(result1)
# Example 2: 1->2->3->4->5, k = 7 (invalid k, unchanged)
list1 = buildList([1, 2, 3, 4, 5])
result2 = swapKth(list1, 7)
print("Input: 1->2->3->4->5, k=7\nOutput: ", end="")
printList(result2)
