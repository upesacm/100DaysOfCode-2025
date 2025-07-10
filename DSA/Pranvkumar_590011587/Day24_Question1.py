class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def print_list(head):
    while head:
        print(head.data, end=" -> ")
        head = head.next
    print("NULL")

# 1. Reverse a Linked List
def reverse_linked_list(head):
    prev = None
    current = head
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    return prev

# --- Test Cases ---
# Example 1: 1 -> 2 -> 3 -> 4
list = Node(1)
list.next = Node(2)
list.next.next = Node(3)
list.next.next.next = Node(4)
print("Original:")
print_list(list)
list = reverse_linked_list(list)
print("Reversed:")
print_list(list)
# Example 2: 2 -> 7 -> 10 -> 9 -> 8
list1 = Node(2)
list1.next = Node(7)
list1.next.next = Node(10)
list1.next.next.next = Node(9)
list1.next.next.next.next = Node(8)
print("\nOriginal:")
print_list(list1)
list1 = reverse_linked_list(list1)
print("Reversed:")
print_list(list1)
# Example 3: 2 -> NULL
list3 = Node(2)
print("\nOriginal:")
print_list(list3)
list3 = reverse_linked_list(list3)
print("Reversed:")
print_list(list3)