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
p1 = first_head
head = None
current = None
while p1 is not None:
    p2 = second_head
    while p2 is not None:
        if p1.data == p2.data:
          
          val = p1.data
          new_node = Node(val)
          if head is None:
              head = new_node
              current = new_node
          else:
              current.next = new_node
              current = new_node
        p2 = p2.next
    p1 = p1.next
p3 = head
while p3 is not None:
    print(p3.data)
    p3 = p3.next
