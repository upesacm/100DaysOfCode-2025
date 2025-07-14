class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def getIntersection(head1, head2):
    dummy = ListNode()
    tail = dummy
    while head1 and head2:
        if head1.val == head2.val:
            tail.next = ListNode(head1.val)
            tail = tail.next
            head1 = head1.next
            head2 = head2.next
        elif head1.val < head2.val:
            head1 = head1.next
        else:
            head2 = head2.next
    return dummy.next

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

head1 = create_linked_list([1, 2, 3, 4, 6])
head2 = create_linked_list([2, 4, 6, 8])
result1 = getIntersection(head1, head2)
print_linked_list(result1)

head3 = create_linked_list([10, 20, 40, 50])
head4 = create_linked_list([15, 40])
result2 = getIntersection(head3, head4)
print_linked_list(result2)
