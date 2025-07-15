class Node:
    def __init__(self, val):
        self.val = val
        self.prev = None
        self.next = None

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
        print(head.val, end=" <--> " if head.next else "")
        head = head.next
    print()

def delete_node_at_position(head, pos):
    if not head or pos <= 0:
        return head

    current = head
    count = 1

    # Traverse to the node at position `pos`
    while current and count < pos:
        current = current.next
        count += 1

    if not current:
        return head  # Position out of bounds

    # If deleting the head
    if current.prev is None:
        head = current.next
        if head:
            head.prev = None
        return head

    # If deleting the tail or middle
    if current.prev:
        current.prev.next = current.next
    if current.next:
        current.next.prev = current.prev

    return head
class Node:
    def __init__(self, val):
        self.val = val
        self.prev = None
        self.next = None

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
        print(head.val, end=" <--> " if head.next else "")
        head = head.next
    print()

def delete_node_at_position(head, pos):
    if not head or pos <= 0:
        return head

    current = head
    count = 1

    # Traverse to the node at position `pos`
    while current and count < pos:
        current = current.next
        count += 1

    if not current:
        return head  # Position out of bounds

    # If deleting the head
    if current.prev is None:
        head = current.next
        if head:
            head.prev = None
        return head

    # If deleting the tail or middle
    if current.prev:
        current.prev.next = current.next
    if current.next:
        current.next.prev = current.prev

    return head

head = make_dll([1, 5, 2, 9])
print("Before deletion:")
print_dll(head)

x = 1
head = delete_node_at_position(head, x)

print("After deleting position", x)
print_dll(head)

