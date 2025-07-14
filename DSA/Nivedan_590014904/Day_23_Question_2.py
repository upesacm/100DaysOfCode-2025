class Node:
    def __init__(self,data,next_node=None):
        self.data = data
        self.next = next_node
n = int(input("Enter the number of nodes: "))
head =None
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
p1 = head
p2 = head
while p1 is not None and p1.next is not None:
    if p1.data == p1.next.data :
        p1.next = p1.next.next
    else:
        p1=p1.next
while p2 is not None:
    print(p2.data)
    p2=p2.next
