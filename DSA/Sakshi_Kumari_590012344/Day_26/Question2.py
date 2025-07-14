class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def makeUnion(head1, head2):
    values = set()

    if head1:
        temp = head1
        while temp:
            values.add(temp.data)
            temp = temp.next

    if head2:
        temp = head2
        while temp:
            values.add(temp.data)
            temp = temp.next

    if not values:
        return None

    sorted_values = sorted(values)

    dummy = Node(0)
    curr = dummy
    for val in sorted_values:
        curr.next = Node(val)
        curr = curr.next

    return dummy.next

def printList(head):
    if not head:
        print("Empty List")
        return
    while head:
        print(head.data, end=" -> " if head.next else "\n")
        head = head.next

