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

def delete_pattern(m, n):
    global head, size
    current = head
    freenode = None
    if m == 0:
        while head:
            i = 0
            while i < n:
                if head:
                    freenode = head
                    head = head.next
                    del freenode
                    size -= 1
                i += 1
        return
    while current:
        i = 1
        while i < m:
            if current:
                current = current.next
            i += 1
        if current is None:
            break
        if current.next is None:
            break
        freenode = current.next
        i = 0
        while i < n:
            if freenode:
                temp = freenode
                freenode = freenode.next
                del temp
                size -= 1
            i += 1
        current.next = freenode
        current = freenode

create_node(1)
create_node(2)
create_node(3)
create_node(4)
create_node(5)
create_node(6)

m = int(input("Enter m : "))
n = int(input("Enter n : "))

print("Before : ", end="")
print_list()

print("After : ", end="")
delete_pattern(m, n)
print_list()
