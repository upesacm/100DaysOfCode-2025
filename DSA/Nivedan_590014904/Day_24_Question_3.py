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
x = int(input("Enter the position you want to remove(x): "))
p1 = head
if x > num or x<1:
    print("-1")
else:
    if x == 1:
        head = head.next
    else:
        for i in range(x-2):
          if p1.next is not None:
            p1 = p1.next
        if p1.next is not None:
          p1.next = p1.next.next
    while head is not None:
       print(head.data)
       head = head.next
