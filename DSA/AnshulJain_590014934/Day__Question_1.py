class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert(root, val):
    if not root:
        return Node(val)
    if val < root.val:
        root.left = insert(root.left, val)
    else:
        root.right = insert(root.right, val)
    return root

def range_sum(root, L, R):
    if not root:
        return 0
    if root.val < L:
        return range_sum(root.right, L, R)
    if root.val > R:
        return range_sum(root.left, L, R)
    return root.val + range_sum(root.left, L, R) + range_sum(root.right, L, R)

n = int(input("Enter number of nodes: "))
values = list(map(int, input("Enter node values: ").split()))
L, R = map(int, input("Enter L and R: ").split())

root = None
for v in values:
    root = insert(root, v)

print("Range Sum:", range_sum(root, L, R))
