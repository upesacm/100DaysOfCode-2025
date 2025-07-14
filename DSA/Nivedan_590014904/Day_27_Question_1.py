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
x = int(input("ENter the value of x: "))
p1 = head
if x == 1:
    head = head.next
    head.prev = None
elif x>num:
    print(-1)
elif x < 1:
    print("-1")
else:
    for i in range(x-1):
        if p1 is not None:
          p1 = p1.next
        else:
            break
    if p1.prev is not None:
        p1.prev.next = p1.next
    if p1.next is not None:
        p1.next.prev = p1.prev
p2 = head
while p2 is not None:
    print(p2.data)
    p2 = p2.next
