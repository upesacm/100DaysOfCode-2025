# Traverse and print all elements of a linked list in the correct order with proper spacing. 
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

def print_linked_list(head):
    current = head
    while current:
        print current.value,
        current = current.next

def create_linked_list(values):
    if not values:
        return None

    head = Node(values[0])
    current = head
    for val in values[1:]:
        current.next = Node(val)
        current = current.next
    return head

input_str = raw_input("Enter linked list elements (space-separated): ")
values = map(int, input_str.strip().split())

head = create_linked_list(values)
print_linked_list(head)
