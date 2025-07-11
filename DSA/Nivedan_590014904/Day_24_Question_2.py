class Node:
    def __init__(self,data,next_node=None):
        self.data = data
        self.next = next_node
num = int(input("Enter the number of nodes to be put in the linked list : "))
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
        current = new_node
n  = int(input("Enter the number of nodes you want to delete(n): "))
m = int(input("Enter the number of nodes you want to skip(m): "))
p1 = head
p3 = head
if n+m < num:
    for i in range(m):
       p2 = p1
       p1=p1.next
    for i in range(n):
       p1 = p1.next
p2.next = p1
while p3 is not None:
    print(p3.data)
    p3 = p3.nextclass Node:
    def __init__(self,data,next_node=None):
        self.data = data
        self.next = next_node
num = int(input("Enter the number of nodes to be put in the linked list : "))
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
        current = new_node
n  = int(input("Enter the number of nodes you want to delete(n): "))
m = int(input("Enter the number of nodes you want to skip(m): "))
p1 = head
p3 = head
if n+m < num:
    for i in range(m):
       p2 = p1
       p1=p1.next
    for i in range(n):
       p1 = p1.next
p2.next = p1
while p3 is not None:
    print(p3.data)
    p3 = p3.next
