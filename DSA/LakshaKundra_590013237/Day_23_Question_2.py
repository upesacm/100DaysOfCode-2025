class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def remove_duplicates(head):
    current = head
    while current and current.next:
        if current.data == current.next.data:
            current.next = current.next.next
        else:
            current = current.next
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
    print(" -> ".join(res))

head1 = create_linked_list([2,2,4,5])
head1 = remove_duplicates(head1)
print_linked_list(head1)  # Output: 2 -> 4 -> 5

head2 = create_linked_list([2,2,2,2,2])
head2 = remove_duplicates(head2)
print_linked_list(head2)  # Output: 2
