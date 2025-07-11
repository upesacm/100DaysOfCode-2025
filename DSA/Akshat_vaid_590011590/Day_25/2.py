class Node:
    def __init__(self, value):
        self.val = value
        self.next = None

def make_linked_list(values):
    if not values:
        return None
    head = Node(values[0])
    pointer = head
    for v in values[1:]:
        pointer.next = Node(v)
        pointer = pointer.next
    return head

def print_list(head):
    current = head
    while current:
        print(current.val, end=" -> " if current.next else "")
        current = current.next
    print()

def intersection_of_sorted_lists(list1, list2):
    
    start = Node(0)       
    tail = start          

    a = list1
    b = list2

    while a and b:
        if a.val == b.val:
            tail.next = Node(a.val)  
            tail = tail.next
            a = a.next
            b = b.next
        elif a.val < b.val:
            a = a.next
        else:
            b = b.next

    return start.next  


list1 = make_linked_list([1, 2, 3, 4, 6])
list2 = make_linked_list([2, 4, 6, 8])

print("List 1:")
print_list(list1)
print("List 2:")
print_list(list2)

result = intersection_of_sorted_lists(list1, list2)

print("Intersection:")
print_list(result)
