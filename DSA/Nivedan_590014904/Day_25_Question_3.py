class Node:
    def __init__(self,data,next_node=None):
        self.data = data
        self.next = next_node
n1 = int(input("Enter the number of nodes to be put in the linked list(1) : "))
first_head = None
first_current = None
for i in range(n1):
    first_val = int(input(f"Enter the value of the {i+1} Node: "))
    new1_node = Node(first_val)
    if first_head is None:
       first_head = new1_node
       first_current = new1_node
    else:
        first_current.next = new1_node
        first_current = new1_node

n2 = int(input("Enter the number of nodes to be put in the linked list(2) : "))
second_head = None
second_current = None
for i in range(n2):
    second_val = int(input(f"Enter the value of the {i+1} Node: "))
    new2_node = Node(second_val)
    if second_head is None:
       second_head = new2_node
       second_current = new2_node
    else:
        second_current.next = new2_node
        second_current = new2_node
p1 = None
p2 =first_head
while p2 is not None:
    p3 = p2.next
    p2.next = p1
    p1 = p2
    p2 = p3

p4 = None
p5 = second_head
while p5 is not None:
    p6 = p5.next
    p5.next = p4
    p4 = p5
    p5 = p6
mod = 0
head = None
current = None
while p1 is not None or p4 is not None:
    if p1 is not None and p4 is not None:
        val = p1.data + p4.data + mod
        p1 = p1.next
        p4 = p4.next
    elif p1 is None:
        val = p4.data + mod
        p4 = p4.next
    elif p4 is None:
        val = p1.data + mod
        p1 = p1.next
    mod = val // 10
    new_node = Node(val%10)
    if head is None:
        head = new_node
        current = new_node
    else:
        current.next = new_node
        current = new_node
if mod != 0:
    new_node = Node(mod)
    current.next = new_node
    current = new_node
p = head
p7 = None
while p is not None:
    p8 = p.next
    p.next = p7
    p7 = p
    p = p8
head  = p7
while p7 is not None:
  if head.data == 0:
    head = head.next
  p7 = p7.next
while head is not None:
    print(head.data)
    head = head.next
