class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def make_list(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for val in values[1:]:
        current.next = Node(val)
        current = current.next
    return head

def print_list(head):
    while head:
        print(head.val, end=" -> " if head.next else "")
        head = head.next
    print()

def add_linked_lists(num1, num2):
    carry = 0
    result_head = Node(0)  
    current = result_head

    p1 = num1
    p2 = num2

    while p1 or p2 or carry:
        val1 = p1.val if p1 else 0
        val2 = p2.val if p2 else 0
        total = val1 + val2 + carry

        carry = total // 10
        digit = total % 10

        current.next = Node(digit)
        current = current.next

        if p1:
            p1 = p1.next
        if p2:
            p2 = p2.next

    return result_head.next

num1 = make_list([4, 5])         
num2 = make_list([3, 4, 5])      

result = add_linked_lists(num1, num2)
print("Result:")
print_list(result)
