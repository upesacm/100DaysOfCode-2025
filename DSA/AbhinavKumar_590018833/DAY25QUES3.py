class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def addTwoNumbers(l1, l2):
    dummy = Node(0)
    curr = dummy
    carry = 0

    while l1 or l2 or carry:
        val1 = l1.val if l1 else 0
        val2 = l2.val if l2 else 0

        total = val1 + val2 + carry
        carry = total // 10
        curr.next = Node(total % 10)
        curr = curr.next

        if l1:
            l1 = l1.next
        if l2:
            l2 = l2.next

    return dummy.next

def build_linked_list(values):
    head = Node(values[0])
    curr = head
    for v in values[1:]:
        curr.next = Node(v)
        curr = curr.next
    return head

def print_linked_list(head):
    while head:
        print(head.val, end=" -> " if head.next else "\n")
        head = head.next

num1 = build_linked_list([4, 5])
num2 = build_linked_list([3, 4, 5])
sum_list = addTwoNumbers(num1, num2)
print("Sum:")
print_linked_list(sum_list)

num1 = build_linked_list([0, 0, 6, 3])
num2 = build_linked_list([0, 7])
sum_list = addTwoNumbers(num1, num2)
print("Sum:")
print_linked_list(sum_list)  
