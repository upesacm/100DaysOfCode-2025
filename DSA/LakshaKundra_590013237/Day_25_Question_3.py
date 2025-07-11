class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverse(head):
    prev = None
    while head:
        nxt = head.next
        head.next = prev
        prev = head
        head = nxt
    return prev

def addLinkedLists(l1, l2):
    l1 = reverse(l1)
    l2 = reverse(l2)
    carry = 0
    dummy = ListNode()
    curr = dummy
    while l1 or l2 or carry:
        v1 = l1.val if l1 else 0
        v2 = l2.val if l2 else 0
        total = v1 + v2 + carry
        curr.next = ListNode(total % 10)
        carry = total // 10
        curr = curr.next
        if l1: l1 = l1.next
        if l2: l2 = l2.next
    return reverse(dummy.next)

def create_linked_list(arr):
    dummy = ListNode()
    curr = dummy
    for num in arr:
        curr.next = ListNode(num)
        curr = curr.next
    return dummy.next

def print_linked_list(head):
    while head:
        print(head.val, end="->" if head.next else "\n")
        head = head.next

head1 = create_linked_list([1, 9, 0])
head2 = create_linked_list([2, 5])
result1 = addLinkedLists(head1, head2)
print_linked_list(result1)

head3 = create_linked_list([4, 5])
head4 = create_linked_list([3, 4, 5])
result2 = addLinkedLists(head3, head4)
print_linked_list(result2)

head5 = create_linked_list([0, 0, 6, 3])
head6 = create_linked_list([0, 7])
result3 = addLinkedLists(head5, head6)
print_linked_list(result3)
