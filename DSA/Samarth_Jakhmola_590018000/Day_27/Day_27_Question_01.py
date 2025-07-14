class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def delete_node(head, x):
    if head is None:
        return None
    
    current = head
    count = 1

    while current and count < x:
        current = current.next
        count += 1

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
x = int(input("Enter position to delete : "))

head = build_doubly_linked_list(LinkedList)
head = delete_node(head, x)

print_doubly_linked_list(head)
