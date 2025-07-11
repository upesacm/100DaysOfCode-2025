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
slow = head
fast = head
while fast and fast.next is not None:
    fast = fast.next.next
    slow = slow.next
p1=None
while slow is not None:
    p2 = slow.next
    slow.next = p1
    p1 = slow
    slow = p2
second = p1
first = head
while second is not None:
    if first.data != second.data:
       print("It's not a Palindrome")
       break
    first = first.next
    second = second.next
else:
    print("It's a Palindrome")
