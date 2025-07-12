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

# Task 2: Reverse a doubly linked list
def reverse_doubly_linked_list(head):
    if not head:
        return None
    curr = head
    prev = None
    while curr:
        curr.prev, curr.next = curr.next, curr.prev
        prev = curr
        curr = curr.prev
    return prev  

lst = create_doubly_linked_list([3, 4, 5])
lst = reverse_doubly_linked_list(lst)
print_doubly_linked_list(lst) 

list = create_doubly_linked_list([75, 122, 59, 196])
list = reverse_doubly_linked_list(list)
print_doubly_linked_list(list)  