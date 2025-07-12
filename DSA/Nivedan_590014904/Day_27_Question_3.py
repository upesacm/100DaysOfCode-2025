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
k = int(input("Enter the value of K: "))
p1 = head 
counter = 0
if k == 0:
    print("-1")
elif k>num:
    print("-1")
else:
    while p1 is not None:
       counter+=1
       p2 = p1.next
       if counter % k == 0:
           if p1.prev is not None:
            p1.prev.next = p1.next
           if p1.next is not None:
            p1.next.prev = p1.prev
       p1 = p2
p3 = head
while p3 is not None:
    print(p3.data)
    p3 = p3.next
