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

def traverse(k):
    global head
    fast = head
    slow = head
    for i in range(k):
        if fast is None:
            return -1
        fast = fast.next
    while fast:
        fast = fast.next
        slow = slow.next
    return slow.data

create_node(1)
create_node(2)
create_node(3)
create_node(4)
create_node(5)

print("The Linked List : ", end="")
print_list()

pos = int(input("Enter the kth position: "))
if pos < 1 or pos > size:
    print("Invalid Position!")
else:
    print("The element at ", pos ,"position is", traverse(pos))
