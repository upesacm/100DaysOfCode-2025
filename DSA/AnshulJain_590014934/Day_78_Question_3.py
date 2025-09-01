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

def find_min(root):
    while root.left:
        root = root.left
    return root.val

def find_max(root):
    while root.right:
        root = root.right
    return root.val

n = int(input())
values = list(map(int, input().split()))
root = None
for v in values:
    root = insert(root, v)
print("Min =", find_min(root), ", Max =", find_max(root))
