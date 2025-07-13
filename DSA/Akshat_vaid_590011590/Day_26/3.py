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

def sort_linked_list(head):
    
    zero_head = zero_tail = None
    one_head = one_tail = None
    two_head = two_tail = None

    current = head

    while current:
        next_node = current.next
        current.next = None  

        if current.val == 0:
            if zero_head is None:
                zero_head = zero_tail = current
            else:
                zero_tail.next = current
                zero_tail = current
        elif current.val == 1:
            if one_head is None:
                one_head = one_tail = current
            else:
                one_tail.next = current
                one_tail = current
        else:
            if two_head is None:
                two_head = two_tail = current
            else:
                two_tail.next = current
                two_tail = current

        current = next_node

    
    new_head = None

    if zero_head:
        new_head = zero_head
        if one_head:
            zero_tail.next = one_head
            if two_head:
                one_tail.next = two_head
        elif two_head:
            zero_tail.next = two_head

    elif one_head:
        new_head = one_head
        if two_head:
            one_tail.next = two_head

    else:
        new_head = two_head

    return new_head

head = make_list([1, 2, 2, 1, 2, 0, 2, 2])
print("Before sorting:")
print_list(head)

sorted_head = sort_linked_list(head)
print("After sorting:")
print_list(sorted_head)
