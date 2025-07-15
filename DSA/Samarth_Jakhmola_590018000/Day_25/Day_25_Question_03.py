class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def reverse(head):
    prev = None 
    current = head
    while current:
        nxt = current.next
        current.next = prev
        prev = current
        current = nxt
    return prev

def add_linked_lists(head1, head2):
    head1 = reverse(head1)
    head2 = reverse(head2)

    carry = 0
    dummy = Node(0)
    current = dummy 

    while head1 or head2 or carry:
        val1 = head1.data if head1 else 0
        val2 = head2.data if head2 else 0

        total = val1 + val2 + carry 
        carry = total // 10
        current.next = Node(total % 10)
        current = current.next

        if head1:
            head1 = head1.next
        if head2:
            head2 = head2.next

    result = reverse(dummy.next)

    while result and result.data == 0 and result.next:
        result = result.next

    return result

def create_linked_list(array):
        head = Node(array[0])
        current = head
        for val in array[1:]:
            current.next = Node(val)
            current = current.next
        return head

def print_linked_list(head):
    result = []
    while head:
        print(head.data, end = "->")
        head = head.next
    print("->".join(result) + "->NULL" if result else "NULL")

elements1 = list(map(int, input("Enter num1 : ").split()))
elements2 = list(map(int, input("Enter num2 : ").split()))

num1 = create_linked_list(elements1)
num2 = create_linked_list(elements2)

result = add_linked_lists(num1, num2)
print_linked_list(result)
