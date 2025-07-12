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

def delete_every_kth(k):
    global head, size
    if head is None or k <= 0:
        return

    if k == 1:
        current = head
        while current:
            temp = current
            current = current.next
            del temp
        head = None
        size = 0
        return

    count = 1
    current = head
    prev = None

    while current:
        if count % k == 0:
            prev.next = current.next
            temp = current
            current = current.next
            del temp
            size -= 1
        else:
            prev = current
            current = current.next
        count += 1

create_node(3)
create_node(4)
create_node(5)
create_node(6)
create_node(7)
create_node(8)
create_node(9)
create_node(10)

print("Before :", end=" ")
print_list()

delete_every_kth(2)

print("After :", end=" ")
print_list()
