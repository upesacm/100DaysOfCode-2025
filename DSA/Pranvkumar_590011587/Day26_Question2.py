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
# 2. Union of Two Linked Lists
def makeUnion(head1, head2):
    s = set()
    while head1:
        s.add(head1.data)
        head1 = head1.next
    while head2:
        s.add(head2.data)
        head2 = head2.next
    sorted_vals = sorted(s)
    dummy = Node(-1)
    curr = dummy
    for val in sorted_vals:
        curr.next = Node(val)
        curr = curr.next
    return dummy.next
# Example 1
l1 = buildList([9,6,4,2,3,8])
l2 = buildList([1,2,8,6,2])
resUnion1 = makeUnion(l1, l2)
print("Input: L1=9->6->4->2->3->8, L2=1->2->8->6->2\nOutput: ", end="")
printList(resUnion1)
# Example 2
l3 = buildList([1,5,1,2,2,5])
l4 = buildList([4,5,6,7,1])
resUnion2 = makeUnion(l3, l4)
print("Input: L1=1->5->1->2->2->5, L2=4->5->6->7->1\nOutput: ", end="")
printList(resUnion2)