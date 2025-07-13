class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
def create_list(values):
    head = Node(values[0]) if values else None
    curr = head
    for v in values[1:]:
        node = Node(v)
        curr.next = node
        curr = node
    return head
def remove_every_kth_node(head, k):
    if k <= 0: return head
    dummy = Node(0)
    dummy.next = head
    prev, curr, count = dummy, head, 1
    while curr:
        if count % k == 0:
            prev.next = curr.next
        else:
            prev = curr
        curr = curr.next
        count += 1
    return dummy.next
def print_list(head):
    while head:
        print(head.data, end=' ')
        head = head.next
head = create_list(list(map(int, input().split())))
k = int(input())
head = remove_every_kth_node(head, k)
print_list(head)
#for example input: 1 2 3 4 5 and 2
#output will be: 1 3 5