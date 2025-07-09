class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def delete_node(head, x):
    if x == 1:
        return head.next
    current = head
    for _ in range(x - 2):
        if current is None or current.next is None:
            return head
        current = current.next
    if current.next:
        current.next = current.next.next
    return head

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

head1 = create_linked_list([1, 3, 4])
head1 = delete_node(head1, 3)
print_linked_list(head1)  # Output: 1->3

head2 = create_linked_list([1, 5, 2, 9])
head2 = delete_node(head2, 2)
print_linked_list(head2)  # Output: 1->2->9
