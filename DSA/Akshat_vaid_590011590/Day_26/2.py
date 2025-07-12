class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def make_list(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for v in values[1:]:
        current.next = Node(v)
        current = current.next
    return head

def print_list(head):
    while head:
        print(head.val, end=" -> " if head.next else "")
        head = head.next
    print()

def make_union(l1, l2):
    unique_values = set()
    
    current = l1
    while current:
        unique_values.add(current.val)
        current = current.next
    
    current = l2
    while current:
        unique_values.add(current.val)
        current = current.next
    
    sorted_vals = sorted(list(unique_values))


    if not sorted_vals:
        return None

    union_head = Node(sorted_vals[0])
    current = union_head
    for val in sorted_vals[1:]:
        current.next = Node(val)
        current = current.next

    return union_head


L1 = make_list([9, 6, 4, 2, 3, 8])
L2 = make_list([1, 2, 8, 6, 2])

print("Union of lists:")
union_list = make_union(L1, L2)
print_list(union_list)
