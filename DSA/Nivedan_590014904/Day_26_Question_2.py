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
p1 =first_head
p2 = second_head
head  = None
current  = None
while p1 is not None:
    val = p1.data
    new_node = Node(val)
    if head is None:
        head = new_node
        current = new_node
    else:
        current.next = new_node
        current = new_node
    p1 = p1.next
while p2 is not None:
    val = p2.data
    new_node = Node(val)
    current.next = new_node
    current = new_node
    p2 = p2.next
p3  = head 
while p3 is not None:
    p4  = p3
    while p4.next is not None:
        if p4.next.data == p3.data:
            p4.next = p4.next.next
        else:
            p4 = p4.next
    p3 = p3.next
p4 = head
while p4 is not None:
    p5 = head
    while p5.next is not None:
        if p5.data > p5.next.data:
            p5.data , p5.next.data = p5.next.data , p5.data        
        p5 = p5.next
    p4 = p4.next
while head is not None:
    print(head.data)
    head  = head.next
