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

def delete_at_pos(head, pos):
    if pos <= 0 or not head: return head
    if pos == 1: return head.next if not head.next else (head.next.__setattr__('prev', None) or head.next)
    curr = head
    for _ in range(pos - 1):
        if not curr: return head
        curr = curr.next
    if not curr: return head
    if curr.prev: curr.prev.next = curr.next
    if curr.next: curr.next.prev = curr.prev
    return head

def print_list(head):
    while head:
        print(head.data, end=' ')
        head = head.next

head = create_list(list(map(int, input().split())))
head = delete_at_pos(head, int(input()))
print_list(head)
#for example input: 1 2 3 4 5 and 3
#output will be: 1 2 4 5