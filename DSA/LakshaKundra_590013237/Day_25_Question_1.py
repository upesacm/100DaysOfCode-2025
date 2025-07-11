class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def isPalindrome(head):
    slow = fast = head
    prev = None
    while fast and fast.next:
        fast = fast.next.next
        tmp = slow.next
        slow.next = prev
        prev = slow
        slow = tmp
    if fast:
        slow = slow.next
    while prev and slow:
        if prev.val != slow.val:
            return False
        prev = prev.next
        slow = slow.next
    return True

def create_linked_list(arr):
    dummy = ListNode()
    current = dummy
    for num in arr:
        current.next = ListNode(num)
        current = current.next
    return dummy.next

head1 = create_linked_list([1, 2, 1, 1, 2, 1])
print(isPalindrome(head1))

head2 = create_linked_list([1, 2, 3, 4])
print(isPalindrome(head2))
