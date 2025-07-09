class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def find_kth_from_end(head, k):
    fast = head
    slow = head
    
    for _ in range(k):
        if not fast:
            return -1
        fast = fast.next
    
    while fast:
        slow = slow.next
        fast = fast.next
    
    return slow.val

head = ListNode(1)
current = head
for i in range(2, 10):
    current.next = ListNode(i)
    current = current.next

k = 2
print(find_kth_from_end(head, k))