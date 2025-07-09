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

def reverse_list():
    global head
    current = head
    ahead = head
    before = None
    while current:
        ahead = ahead.next
        current.next = before
        before = current
        current = ahead
    head = before

create_node(1)
create_node(2)
create_node(3)
create_node(4)
create_node(5)
create_node(6)

print("Before : ", end="")
print_list()

print("After : ", end="")
reverse_list()
print_list()
