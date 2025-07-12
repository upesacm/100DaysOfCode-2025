class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None

def make_dll(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for v in values[1:]:
        new_node = Node(v)
        current.next = new_node
        new_node.prev = current
        current = new_node
    return head

def print_dll(head):
    while head:
        print(head.val, end=" <-> " if head.next else "")
        head = head.next
    print()

def reverse_dll(head):
    if not head or not head.next:
        return head

    current = head
    while current:
        # Swap next and prev
        current.prev, current.next = current.next, current.prev
        # Move to the previous node (which is next before swapping)
        head = current  # update head to current before moving
        current = current.prev

    return head

head = make_dll([3, 4, 5])
print("Before reversing:")
print_dll(head)

reversed_head = reverse_dll(head)
print("After reversing:")
print_dll(reversed_head)
