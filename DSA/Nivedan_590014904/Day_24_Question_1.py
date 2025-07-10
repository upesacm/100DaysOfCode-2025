class Node:
    def __init__(self,data,next_node=None):
        self.data = data
        self.next = next_node
n = int(input("Enter the number of nodes to be put in the linked list : "))
head = None
current = None
for i in range(n):
    val = int(input(f"Enter the value of the {i+1} Node: "))
    new_node = Node(val)
    if head is None:
       head = new_node
       current = new_node
    else:
        current.next = new_node
        current = new_node
p1 = None
p2 = head
while p2 is not None:
    p3 = p2.next
    p2.next = p1
    p1 = p2
    p2 = p3
while p1 is not None:
    print(p1.data)
    p1= p1.next
