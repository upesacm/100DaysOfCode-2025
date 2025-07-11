def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
    dummy = ListNode(0)
    tail = dummy
    carry = 0

    while l1 or l2 or carry:
        val1 = l1.val if l1 else 0
        val2 = l2.val if l2 else 0

        total = val1 + val2 + carry
        carry = total // 10
        tail.next = ListNode(total % 10)
        tail = tail.next

        if l1: l1 = l1.next
        if l2: l2 = l2.next

    return dummy.next
