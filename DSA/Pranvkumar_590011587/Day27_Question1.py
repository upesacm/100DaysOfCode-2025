class DoublyNode:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def create_doubly_linked_list(arr):
    if not arr:
        return None
    head = DoublyNode(arr[0])
    curr = head
    for val in arr[1:]:
        node = DoublyNode(val)
        curr.next = node
        node.prev = curr
        curr = node
    return head

def print_doubly_linked_list(head):
    result = []
    while head:
        result.append(str(head.data))
        head = head.next
    print(" <--> ".join(result))

# Task 1: Delete node at a specific position in a doubly linked list
def delete_node_at_position(head, pos):
    if not head or pos <= 0:
        return head
    curr = head
    count = 1
    if pos == 1:
        if head.next:
            head = head.next
            head.prev = None
        else:
            head = None
        return head
    while curr and count < pos:
        curr = curr.next
        count += 1
    if not curr:
        return head
    if curr.prev:
        curr.prev.next = curr.next
    if curr.next:
        curr.next.prev = curr.prev
    return head

list1 = create_doubly_linked_list([1, 3, 4])
list1 = delete_node_at_position(list1, 3)
print_doubly_linked_list(list1) 

list = create_doubly_linked_list([1, 5, 2, 9])
list = delete_node_at_position(list, 1)
print_doubly_linked_list(list)  