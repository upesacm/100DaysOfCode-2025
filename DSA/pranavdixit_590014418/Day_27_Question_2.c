def reverseDLL(head):
    current = head
    prev_node = None

    while current:
        current.prev, current.next = current.next, current.prev
        prev_node = current
        current = current.prev

    return prev_node

# Sample Test
n1 = Node(3)
n2 = Node(4)
n3 = Node(5)
n1.next = n2
n2.prev = n1
n2.next = n3
n3.prev = n2

head = reverseDLL(n1)
printList(head)
