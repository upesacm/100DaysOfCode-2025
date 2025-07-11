class Node:
    def __init__(self, val=0, next=None): self.val, self.next = val, next
def build(vals):
    n = Node(0)
    t = n
    for v in vals: t.next = Node(v); t = t.next
    return n.next
def show(h):
    while h: print(h.val, end=" -> " if h.next else "\n"); h = h.next
def makeUnion(a, b):
    s = sorted(set(get_vals(a)) | set(get_vals(b)))
    d = Node(0)
    t = d
    for v in s: t.next = Node(v); t = t.next
    return d.next
def get_vals(n):
    while n: yield n.val; n = n.next
a = build(list(map(int, input().split())))
b = build(list(map(int, input().split())))
show(makeUnion(a, b))
#Taking input from the user
# Example input for list a: 1 2 3
# list b: 2 3 4
# output: 1 -> 2 -> 3 -> 4 ->