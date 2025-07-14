class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

head = None
size = 0

def create_node(data):
    global head, size
    new_node = Node(data)
    if head is None:
        head = new_node
        size += 1
        return
    current = head
    while current.next:
        current = current.next
    current.next = new_node
    new_node.prev = current
    size += 1

def print_list():
    current = head
    while current:
        if current.next:
            print(current.data, "<-->", end=" ")
        else:
            print(current.data)
        current = current.next

def reverse_list():
    global head
    if head is None or head.next is None:
        return

    current = head
    temp = None

    while current:
        temp = current.prev
        current.prev = current.next
        current.next = temp
        current = current.prev

    if temp:
        head = temp.prev

create_node(3)
create_node(4)
create_node(5)

print("Before :", end=" ")
print_list()

reverse_list()

print("After :", end=" ")
print_list()
