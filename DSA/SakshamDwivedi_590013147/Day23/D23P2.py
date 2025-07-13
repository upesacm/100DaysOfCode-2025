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

def remove_dups():
    global head, size
    trav1 = head
    trav2 = head.next if head else None

    while trav2:
        if trav1.data == trav2.data:
            trav1.next = trav2.next
            trav2 = trav2.next
            size -= 1
        else:
            trav1 = trav1.next
            trav2 = trav2.next

create_node(1)
create_node(2)
create_node(2)
create_node(2)
create_node(3)
create_node(4)
create_node(4)
create_node(4)
create_node(4)
create_node(4)
create_node(5)

print("Before : ", end="")
print_list()

print("After : ", end="")
remove_dups()
print_list()
