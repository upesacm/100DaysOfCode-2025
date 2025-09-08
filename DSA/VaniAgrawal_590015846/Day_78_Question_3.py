# Minimum & Maximum in BST
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def build_tree(values):
    if not values: return None
    nodes = [None if v == "null" else Node(int(v)) for v in values]
    kids = nodes[::-1]
    root = kids.pop()
    for node in nodes:
        if node:
            if kids: node.left = kids.pop()
            if kids: node.right = kids.pop()
    return root

def find_min(root):
    while root and root.left:
        root = root.left
    return root.val if root else None

def find_max(root):
    while root and root.right:
        root = root.right
    return root.val if root else None

values = input().split()
root = build_tree(values)
print("Min =", find_min(root), "Max =", find_max(root))
