def intersectSortedLists(head1: ListNode, head2: ListNode) -> ListNode:
    dummy = ListNode(0)
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
