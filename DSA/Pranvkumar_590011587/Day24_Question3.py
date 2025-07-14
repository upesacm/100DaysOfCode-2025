class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def print_list(head):
    while head:
        print(head.data, end=" -> ")
        head = head.next
    print("NULL")

# 3. Delete a node at a specific position (1-based)
def delete_at_position(head, x):
    if x == 1:
        return head.next
    current = head
    count = 1
    while current is not None and count < x - 1:
        current = current.next
        count += 1
    if current is not None and current.next is not None:
        current.next = current.next.next
    return head

# --- Test Cases ---
# Example 1: 1 -> 3 -> 4, x = 3
list = Node(1)
list.next = Node(3)
list.next.next = Node(4)
print("Original:")
print_list(list)
list = delete_at_position(list, x=3)
print("After deleting node at position 3:")
print_list(list)
# Example 2: 1 -> 5 -> 2 -> 9, x = 2
list1 = Node(1)
list1.next = Node(5)
list1.next.next = Node(2)
list1.next.next.next = Node(9)
print("\nOriginal:")
print_list(list1)
list1 = delete_at_position(list1, x=2)
print("After deleting node at position 2:")
print_list(list1)