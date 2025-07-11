class Node:
    def __init__(self, value):
        self.data = value
        self.next = None

def reverse(head):
    prev = None
    current = head
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    return prev

def add_linked_lists(l1, l2):
    l1 = reverse(l1)
    l2 = reverse(l2)

    carry = 0
    dummy = Node(0)
    temp = dummy

    while l1 or l2 or carry:
        sum_val = carry
        if l1:
            sum_val += l1.data
            l1 = l1.next
        if l2:
            sum_val += l2.data
            l2 = l2.next

        carry = sum_val // 10
        temp.next = Node(sum_val % 10)
        temp = temp.next

    result = reverse(dummy.next)

    while result and result.data == 0 and result.next:
        result = result.next

    return result

def make_list(arr):
    if not arr:
        return None
    head = Node(arr[0])
    current = head
    for num in arr[1:]:
        current.next = Node(num)
        current = current.next
    return head

def print_list(head):
    while head:
        print(head.data, end=" ")
        head = head.next
    print()

a = list(map(int, input().split()))
b = list(map(int, input().split()))

num1 = make_list(a)
num2 = make_list(b)

result = add_linked_lists(num1, num2)

print_list(result)
