class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
def create_linked_list(values):
    if not values:
        return None
    head = Node(values[0])
    curr = head
    for val in values[1:]:
        curr.next = Node(val)
        curr = curr.next
    return head
def remove_duplicates(head):
    curr = head
    while curr and curr.next:
        if curr.data == curr.next.data:
            curr.next = curr.next.next
        else:
            curr = curr.next
    return head
def print_linked_list(head):
    while head:
        print(head.data, end=' ')
        head = head.next
values = list(map(int, input("Enter sorted linked list elements separated by space: ").split()))
head = create_linked_list(values)
head = remove_duplicates(head)
print_linked_list(head)
