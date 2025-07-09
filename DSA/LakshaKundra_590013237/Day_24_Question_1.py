class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def reverse_linked_list(head):
    prev = None
    current = head
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    return prev

def create_linked_list(arr):
    if not arr:
        return None
    head = Node(arr[0])
    temp = head
    for val in arr[1:]:
        temp.next = Node(val)
        temp = temp.next
    return head

def print_linked_list(head):
    res = []
    while head:
        res.append(str(head.data))
        head = head.next
    print("->".join(res))

head1 = create_linked_list([1, 2, 3, 4])
head1 = reverse_linked_list(head1)
print_linked_list(head1)  # Output: 4->3->2->1

head2 = create_linked_list([2, 7, 10, 9, 8])
head2 = reverse_linked_list(head2)
print_linked_list(head2)  # Output: 8->9->10->7->2

head3 = create_linked_list([2])
head3 = reverse_linked_list(head3)
print_linked_list(head3)  # Output: 2
