class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

head = ListNode(2)
head.next = ListNode(2)
head.next.next = ListNode(4)
head.next.next.next = ListNode(5)

current = head
while current and current.next:
    if current.val == current.next.val:
        current.next = current.next.next
    else:
        current = current.next

result = []
current = head
while current:
    result.append(str(current.val))
    current = current.next
print(" -> ".join(result))
head = ListNode(2)
head.next = ListNode(2)
head.next.next = ListNode(2)
head.next.next.next = ListNode(2)
head.next.next.next.next = ListNode(2)