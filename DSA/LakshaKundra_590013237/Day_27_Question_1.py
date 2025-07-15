class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def deleteNode(head, x):
    if not head:
        return None
    if x == 1:
        head = head.next
        if head:
            head.prev = None
        return head
    temp = head
    for _ in range(x - 1):
        temp = temp.next
    if temp.next:
        temp.next.prev = temp.prev
    if temp.prev:
        temp.prev.next = temp.next
    return head

def printList(head):
    while head:
        print(head.data, end=" ")
        head = head.next
    print()

n1 = Node(1)
n2 = Node(3)
n3 = Node(4)
n1.next = n2
n2.prev = n1
n2.next = n3
n3.prev = n2
head = n1
head = deleteNode(head, 3)
printList(head)

n1 = Node(1)
n2 = Node(5)
n3 = Node(2)
n4 = Node(9)
n1.next = n2
n2.prev = n1
n2.next = n3
n3.prev = n2
n3.next = n4
n4.prev = n3
head = n1
head = deleteNode(head, 1)
printList(head)
