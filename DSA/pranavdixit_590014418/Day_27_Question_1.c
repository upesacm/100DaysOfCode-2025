class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def deleteNode(head, x):
    if head is None:
        return None

    if x == 1:
        if head.next:
            head.next.prev = None
        return head.next

    temp = head
    for _ in range(x - 1):
        if temp is None:
            return head
        temp = temp.next

    if temp is None:
        return head

    if temp.prev:
        temp.prev.next = temp.next
    if temp.next:
        temp.next.prev = temp.prev

    return head

# Sample Test
def printList(head):
    while head:
        print(head.data, end=" <-> " if head.next else "\n")
        head = head.next

n1 = Node(1)
n2 = Node(3)
n3 = Node(4)
n1.next = n2
n2.prev = n1
n2.next = n3
n3.prev = n2

head = deleteNode(n1, 3)
printList(head)
