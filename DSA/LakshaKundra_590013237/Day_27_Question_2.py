class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def reverseDLL(head):
    curr = head
    temp = None
    while curr:
        temp = curr.prev
        curr.prev = curr.next
        curr.next = temp
        curr = curr.prev
    if temp:
        head = temp.prev
    return head

def printList(head):
    while head:
        print(head.data, end=" ")
        head = head.next
    print()

n1 = Node(3)
n2 = Node(4)
n3 = Node(5)
n1.next = n2
n2.prev = n1
n2.next = n3
n3.prev = n2
head = n1
head = reverseDLL(head)
printList(head)

n1 = Node(75)
n2 = Node(122)
n3 = Node(59)
n4 = Node(196)
n1.next = n2
n2.prev = n1
n2.next = n3
n3.prev = n2
n3.next = n4
n4.prev = n3
head = n1
head = reverseDLL(head)
printList(head)
