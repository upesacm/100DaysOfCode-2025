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
def delete_middle(head):
    if not head or not head.next:
        return None
    slow = head
    fast = head
    prev = None
    while fast and fast.next:
        fast = fast.next.next
        prev = slow
        slow = slow.next
    prev.next = slow.next
    return head
def print_linked_list(head):
    while head:
        print(head.data, end=' ')
        head = head.next

values = list(map(int, input("Enter linked list elements separated by space: ").split()))
head = create_linked_list(values)
head = delete_middle(head)
print_linked_list(head)
