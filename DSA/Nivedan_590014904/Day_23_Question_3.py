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
p1 = head
p2 = head
p3 = None
while p2 is not None and p2.next is not None:
    p3 = p1
    p1 = p1.next
    p2 = p2.next.next
p3.next  = p1.next
p = head
while p is not None:
    print(p.data)
    p = p.next
