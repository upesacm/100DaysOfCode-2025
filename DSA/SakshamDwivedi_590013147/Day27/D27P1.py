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

def delete_pos(pos):
    global head, size
    if head is None or pos < 1 or pos > size:
        return

    if pos == 1:
        temp = head
        head = head.next
        if head:
            head.prev = None
        del temp
        size -= 1
        return

    current = head
    count = 1
    while count < pos:
        current = current.next
        count += 1

    if current.next:
        current.next.prev = current.prev
    if current.prev:
        current.prev.next = current.next

    del current
    size -= 1

create_node(1)
create_node(3)
create_node(4)

print("Before :", end=" ")
print_list()

delete_pos(3)

print("After :", end=" ")
print_list()
