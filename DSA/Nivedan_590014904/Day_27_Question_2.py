class Node:
    def __init__(self, data, next_node=None, prev_node=None):
        self.data = data
        self.next = next_node
        self.prev = prev_node

num = int(input("Enter the number of nodes to be put in the doubly linked list: "))
head = None
current = None

for i in range(num):
    val = int(input(f"Enter the value of the {i+1} Node: "))
    new_node = Node(val)
    if head is None:
        head = new_node
        current = new_node
    else:
        current.next = new_node
        new_node.prev = current
        current = new_node
p1 = head
while p1 is not None:
    p2 = p1.prev
    p1.prev = p1.next
    p1.next = p2
    p1 = p1.prev
head = p2.prev
p3 = head
while p3 is not None:
    print(p3.data)
    p3 = p3.next
