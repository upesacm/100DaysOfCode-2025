class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

size = 0
head = None

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
    size += 1

def print_list():
    current = head
    while current:
        if current.next:
            print(current.data, " -> ", end="")
        else:
            print(current.data)
        current = current.next

def delete_position(pos):
    global head, size
    if pos <= 0 or pos > size:
        return
    current = head
    freenode = head
    if pos == 1:
        head = current.next
        del current
        size -= 1
        return
    i = 1
    while i < pos - 1:
        current = current.next
        i += 1
    freenode = current.next
    current.next = freenode.next
    del freenode
    size -= 1

create_node(1)
create_node(2)
create_node(3)
create_node(4)
create_node(5)
create_node(6)

m = int(input("Enter the position : "))

print("Before : ", end="")
print_list()

print("After : ", end="")
delete_position(m)
print_list()
