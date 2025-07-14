class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def reverse_doubly_linked_list(head):
    if head is None:
        return None
    
    current = head
    temp = None

    while current:
        temp = current.prev
        current.prev = current.next
        current.next = temp
        current = current.prev

    if temp:
        head = temp.prev

    return head

def build_doubly_linked_list(array):
    if not array:
        return None
    
    head = Node(array[0])
    current = head
    for val in array[1:]:
        new_node = Node(val)
        current.next = new_node
        new_node.prev = current
        current = new_node
    return head

def print_doubly_linked_list(head):
    result = []
    while head:
        result.append(str(head.data))
        head = head.next
    print(" <--> ".join(result))

LinkedList = list(map(int, input("Enter the elements of the doubly linked list separated by spaces : ").split()))

head = build_doubly_linked_list(LinkedList)
head = reverse_doubly_linked_list(head)

print_doubly_linked_list(head)
