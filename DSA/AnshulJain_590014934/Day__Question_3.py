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

def print_in_range(root, L, R):
    if not root:
        return
    if root.val > L:
        print_in_range(root.left, L, R)
    if L <= root.val <= R:
        print(root.val, end=" ")
    if root.val < R:
        print_in_range(root.right, L, R)

n = int(input("Enter number of nodes: "))
values = list(map(int, input("Enter node values: ").split()))
L, R = map(int, input("Enter L and R: ").split())

root = None
for v in values:
    root = insert(root, v)

print_in_range(root, L, R)
