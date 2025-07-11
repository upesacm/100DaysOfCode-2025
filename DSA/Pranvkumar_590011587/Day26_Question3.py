class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
def printList(head):
    while head:
        print(head.data, end=" -> " if head.next else "")
        head = head.next
    print()
def buildList(arr):
    if not arr:
        return None
    head = Node(arr[0])
    curr = head
    for val in arr[1:]:
        curr.next = Node(val)
        curr = curr.next
    return head
# 3. Sort Linked List of 0s, 1s, 2s
def sortList(head):
    zeroD = Node(0)
    oneD = Node(0)
    twoD = Node(0)
    zero = zeroD
    one = oneD
    two = twoD
    curr = head
    while curr:
        if curr.data == 0:
            zero.next = curr
            zero = zero.next
        elif curr.data == 1:
            one.next = curr
            one = one.next
        else:
            two.next = curr
            two = two.next
        curr = curr.next
    zero.next = oneD.next if oneD.next else twoD.next
    one.next = twoD.next
    two.next = None
    return zeroD.next
# Example 1
list = buildList([1, 2, 2, 1, 2, 0, 2, 2])
sorted = sortList(list)
print("Input: 1->2->2->1->2->0->2->2\nOutput: ", end="")
printList(sorted)
# Example 2
list1 = buildList([2, 2, 0, 1])
sorted1 = sortList(list1)
print("Input: 2->2->0->1\nOutput: ", end="")
printList(sorted1)