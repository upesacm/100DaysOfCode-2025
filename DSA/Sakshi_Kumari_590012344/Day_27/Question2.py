Your task: Reverse a doubly linked list by swapping both forward and backward pointers for 
all nodes.

class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def reverse_doubly_linked_list(head):
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

def print_list(head):
    current = head
    while current:
        print(current.data, end=" ")
        if current.next:
            print("<-->", end=" ")
        current = current.next
    print()

node1 = Node(1)
node2 = Node(2)
node3 = Node(3)
node4 = Node(4)

node1.next = node2
node2.prev = node1
node2.next = node3
node3.prev = node2
node3.next = node4
node4.prev = node3

head = node1
print_list(head)
head = reverse_doubly_linked_list(head)
print_list(head)
