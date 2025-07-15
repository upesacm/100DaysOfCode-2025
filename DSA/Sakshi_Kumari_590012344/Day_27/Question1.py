Your task: Delete a node at a specific position in a doubly linked list while maintaining 
proper forward and backward connections.

class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def delete_node(head, position):
    if head is None or position <= 0:
        return head

    current = head

    if position == 1:
        head = current.next
        if head:
            head.prev = None
        return head

    for i in range(1, position):
        current = current.next
        if current is None:
            return head

    if current.prev:
        current.prev.next = current.next
    if current.next:
        current.next.prev = current.prev

    return head

def print_list(head):
    current = head
    while current:
        print(current.data, end=" ")
        if current.next:
            print("<-->", end=" ")
        current = current.next
    print()

node1 = Node(1)
node2 = Node(3)
node3 = Node(4)

node1.next = node2
node2.prev = node1
node2.next = node3
node3.prev = node2

head1 = node1
print_list(head1)
head1 = delete_node(head1, 3)
print_list(head1)

n1 = Node(1)
n2 = Node(5)
n3 = Node(2)
n4 = Node(9)

n1.next = n2
n2.prev = n1
n2.next = n3
n3.prev = n2
n3.next = n4
n4.prev = n3

head2 = n1
print_list(head2)
head2 = delete_node(head2, 1)
print_list(head2)
