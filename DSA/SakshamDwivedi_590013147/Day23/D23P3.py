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

def remove_mid():
    global head, size
    if head is None or head.next is None:
        return

    mid = size // 2
    count = 1
    trav = head

    while count != mid:
        trav = trav.next
        count += 1

    freetrav = trav.next
    trav.next = trav.next.next
    del freetrav
    size -= 1

create_node(1)
create_node(2)
create_node(3)
create_node(4)
create_node(5)
#create_node(6)

print("Before : ", end="")
print_list()

print("After : ", end="")
remove_mid()
print_list()
