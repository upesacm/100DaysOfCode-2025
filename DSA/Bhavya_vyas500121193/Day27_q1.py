class Node:
    def __init__(self, data): 
        self.data = data
        self.prev = None
        self.next = None

def delete_node(head, x):
    if head is None or x <= 0:
        return head

    current = head

    for _ in range(x - 1):
        if current is None:
            return head  
        current = current.next

    if current is None:
        return head

    if current.prev is None:
        head = current.next
        if head:
            head.prev = None
    else:
        current.prev.next = current.next

    if current.next:
        current.next.prev = current.prev

    return head
def print_list(head):
    while head:
        print(head.data, end=" <--> " if head.next else "\n")
        head = head.next

def build_doubly_linked_list(values):
    head = None
    prev = None
    for val in values:
        node = Node(val)
        if not head:
            head = node
        else:
            prev.next = node
            node.prev = prev
        prev = node
    return head


head1 = build_doubly_linked_list([1, 3, 4])
print("Before:")
print_list(head1)
head1 = delete_node(head1, 3)
print("After:")
print_list(head1)


head2 = build_doubly_linked_list([1, 5, 2, 9])
print("Before:")
print_list(head2)
head2 = delete_node(head2, 1)
print("After:")
print_list(head2)
