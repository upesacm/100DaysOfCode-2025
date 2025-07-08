class Node:
    def __init__(self,data,next_node=None):
        self.data =data
        self.next = next_node
n = int(input("Enter the number of nodes: "))
head = None
current = None
for i in range(n):
    val = int(input(f"Enter the data of the {i+1} node: "))
    new_node = Node(val)
    if head is None:
        head = new_node
        current = new_node
    else:
        current.next = new_node
        current = new_node
k = int(input("Enter thr value of k: "))
if k>n:
    print(-1)
else:
    p1 = head
    p2= head
    for j in range(k):
      p1 = p1.next
    while p1 is not None:
      p1 = p1.next
      p2 = p2.next
    print(p2.data)
