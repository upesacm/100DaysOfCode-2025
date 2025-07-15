class Node:
    def __init__(self, val=0, next=None): self.val, self.next = val, next
def build(vals):
    d = Node(0)
    t = d
    for v in vals: t.next = Node(v); t = t.next
    return d.next
def show(h):
    while h: print(h.val, end=" -> " if h.next else "\n"); h = h.next
def sort012(head):
    z = Node(0)
    o = Node(0)
    t = Node(0)
    zt, ot, tt = z, o, t
    while head:
        if head.val == 0: zt.next = head; zt = zt.next
        elif head.val == 1: ot.next = head; ot = ot.next
        else: tt.next = head; tt = tt.next
        head = head.next
    tt.next = None
    ot.next = t.next
    zt.next = o.next
    return z.next
vals = list(map(int, input().split()))
head = build(vals)
sorted_head = sort012(head)
show(sorted_head)
#takin input from the user 
# Example input: 0 1 2 0 1 2
# Example output: 0 -> 0 -> 1 -> 1 -> 2 ->