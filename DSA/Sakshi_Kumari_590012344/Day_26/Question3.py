Your task: Sort a linked list containing only 0s, 1s, and 2s using efficient partitioning 
techniques without extra space.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def sort012(head):
    zeroList = Node(0)
    oneList = Node(0)
    twoList = Node(0)

    zero = zeroList
    one = oneList
    two = twoList

    current = head
    while current:
        if current.data == 0:
            zero.next = current
            zero = zero.next
        elif current.data == 1:
            one.next = current
            one = one.next
        else:
            two.next = current
            two = two.next
        current = current.next

    zero.next = oneList.next if oneList.next else twoList.next
    one.next = twoList.next
    two.next = None

    return zeroList.next

def printList(head):
    while head:
        print(head.data, end=" -> " if head.next else "\n")
        head = head.next

head = Node(2)
head.next = Node(2)
head.next.next = Node(0)
head.next.next.next = Node(1)

print("Original List:")
printList(head)

sorted_head = sort012(head)

print("Sorted List:")
printList(sorted_head)
