class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def isPalindrome(head):
    if not head or not head.next:
        return True
    
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    
    prev = None
    while slow:
        next_node = slow.next
        slow.next = prev
        prev = slow
        slow = next_node
    
    first = head
    second = prev
    while second:
        if first.val != second.val:
            return False
        first = first.next
        second = second.next
    return True

head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(1)
head.next.next.next = ListNode(1)
head.next.next.next.next = ListNode(2)
head.next.next.next.next.next = ListNode(1)

print(isPalindrome(head))