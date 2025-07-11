class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def build_linked_list(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for val in values[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

def is_palindrome(head):
    if not head or not head.next:
        return True

    slow = head
    fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    prev = None
    curr = slow

    while curr:
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next

    left = head
    right = prev

    while right:
        if left.val != right.val:
            return False
        left = left.next
        right = right.next

    return True

values = [1, 2, 1, 1, 2, 1]
head = build_linked_list(values)
print("Is palindrome:", is_palindrome(head))
