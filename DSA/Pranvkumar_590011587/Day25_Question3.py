class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

#Problem 3: Add Two Numbers as Linked Lists 
def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
    dummy = tail = ListNode(0)
    carry = 0
    while l1 or l2 or carry:
        v1 = l1.val if l1 else 0
        v2 = l2.val if l2 else 0
        total = v1 + v2 + carry
        carry = total // 10
        tail.next = ListNode(total % 10)
        tail = tail.next
        if l1: l1 = l1.next
        if l2: l2 = l2.next
    return dummy.next

def build_linked_list(values):
    dummy = current = ListNode(0)
    for v in values:
        current.next = ListNode(v)
        current = current.next
    return dummy.next

def print_linked_list(head):
    vals = []
    while head:
        vals.append(str(head.val))
        head = head.next
    print(" -> ".join(vals))


if __name__ == "__main__":
    num1 = build_linked_list([4, 5])
    num2 = build_linked_list([3, 4, 5])
    print("Input: 4->5 and 3->4->5")
    result = addTwoNumbers(num1, num2)
    print("Output:", end=" ")
    print_linked_list(result) 

    num3 = build_linked_list([0, 0, 6, 3])
    num4 = build_linked_list([0, 7])
    print("\nInput: 0->0->6->3 and 0->7")
    result = addTwoNumbers(num3, num4)
    print("Output:", end=" ")
    print_linked_list(result)
