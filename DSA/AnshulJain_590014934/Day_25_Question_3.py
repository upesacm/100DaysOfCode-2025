class Node:
    def __init__(self, value=0, next=None): self.value, self.next = value, next
def create_list(numbers):
    curr = head = Node(numbers[0])
    for num in numbers[1:]: curr.next = Node(num); curr = curr.next
    return head
def reverse_list(head):
    prev = None
    while head:
        head.next, prev, head = prev, head, head.next
    return prev
def add_numbers(n1, n2):
    n1 = reverse_list(n1)
    n2 = reverse_list(n2)
    dummy = curr = Node(0); carry = 0
    while n1 or n2 or carry:
        carry += (n1.value if n1 else 0) + (n2.value if n2 else 0)
        curr.next = Node(carry % 10)
        carry //= 10
        curr = curr.next
        n1 = n1.next if n1 else None
        n2 = n2.next if n2 else None
    return reverse_list(dummy.next)
def display_list(node):
    while node: print(node.value, end=' '); node = node.next
num1 = create_list(list(map(int, input("Enter The first linked List:").split()))) # Tking input from the user
num2 = create_list(list(map(int, input("Enter The second Linked List:").split())))
display_list(add_numbers(num1, num2))
#For example:-
# Input:First Linked List: 2 4 3
# second linked list: 5 6 4
# Output: 8 0 7