class Node:
    def __init__(self, data):
        self.data = data
        self.prev = self.next = None
def create_list(values):
    head = Node(values[0]) if values else None
    curr = head
    for v in values[1:]:
        node = Node(v)
        curr.next, node.prev, curr = node, curr, node
    return head
def reverse_list(head):
    curr = head
    while curr:
        curr.prev, curr.next = curr.next, curr.prev
        if not curr.prev: return curr
        curr = curr.prev
def print_list(head):
    while head:
        print(head.data, end=' ')
        head = head.next
head = create_list(list(map(int, input().split())))
head = reverse_list(head)
print_list(head)
#for example input: 1 2 3 4 5
#output will be: 5 4 3 2 1  