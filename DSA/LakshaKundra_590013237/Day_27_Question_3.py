class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def removeKthNode(head, k):
    if k == 0:
        return head
    if k == 1:
        return None
    curr = head
    count = 1
    while curr:
        for _ in range(k - 2):
            if curr.next:
                curr = curr.next
            else:
                return head
        if curr.next:
            curr.next = curr.next.next
            curr = curr.next
        else:
            break
    return head

def printList(head):
    while head:
        print(head.data, end=" ")
        head = head.next
    print()

def createList(arr):
    if not arr:
        return None
    head = Node(arr[0])
    curr = head
    for val in arr[1:]:
        curr.next = Node(val)
        curr = curr.next
    return head

head = createList([1, 2, 3, 4, 5, 6, 7, 8])
head = removeKthNode(head, 2)
printList(head)

head = createList([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
head = removeKthNode(head, 3)
printList(head)
