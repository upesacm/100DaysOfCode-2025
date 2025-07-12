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

def remove_every_kth_node(head, k):
    if k <= 1:
        return None  # remove all nodes
    if not head:
        return None

    current = head
    prev = None
    count = 1

    while current:
        if count % k == 0:
            # Remove current node
            prev.next = current.next
        else:
            prev = current
        current = current.next
        count += 1

    return head

head = make_list([1, 2, 3, 4, 5, 6, 7, 8])
print("Before removing every 2nd node:")
print_list(head)

head = remove_every_kth_node(head, 2)
print("After removing every 2nd node:")
print_list(head)
