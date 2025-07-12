class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def findIntersection(head1, head2):
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

def printList(head):
    while head:
        print(head.val, end=" -> " if head.next else "")
        head = head.next
    print()
list1 = ListNode(1)
list1.next = ListNode(2)
list1.next.next = ListNode(3)
list1.next.next.next = ListNode(4)
list1.next.next.next.next = ListNode(6)

list2 = ListNode(2)
list2.next = ListNode(4)
list2.next.next = ListNode(6)
list2.next.next.next = ListNode(8)

result = findIntersection(list1, list2)
printList(result)  
