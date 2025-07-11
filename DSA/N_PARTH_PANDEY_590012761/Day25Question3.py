class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def addTwoNumbers(num1, num2):
    def reverseList(head):
        prev = None
        while head:
            next_node = head.next
            head.next = prev
            prev = head
            head = next_node
        return prev

    num1 = reverseList(num1)
    num2 = reverseList(num2)

    dummy = ListNode()
    current = dummy
    carry = 0

    while num1 or num2 or carry:
        val1 = num1.val if num1 else 0
        val2 = num2.val if num2 else 0

        total = val1 + val2 + carry
        carry = total // 10
        current.next = ListNode(total % 10)
        current = current.next

        if num1:
            num1 = num1.next
        if num2:
            num2 = num2.next

    result = reverseList(dummy.next)

    while result and result.val == 0 and result.next:
        result = result.next

    return result

def printList(head):
    while head:
        print(head.val, end=" -> " if head.next else "")
        head = head.next
    print()


num1 = ListNode(8)
num1.next = ListNode(6)

num2 = ListNode(3)
num2.next = ListNode(4)
num2.next.next = ListNode(5)

result = addTwoNumbers(num1, num2)
printList(result)  

