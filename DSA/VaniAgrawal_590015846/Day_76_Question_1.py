# Convert to Sum Tree
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

def to_sum_tree(root):
    if not root: return 0
    old_val = root.val
    left = to_sum_tree(root.left)
    right = to_sum_tree(root.right)
    root.val = left + right
    return root.val + old_val

def inorder(root):
    return inorder(root.left) + [root.val] + inorder(root.right) if root else []

values = input().split()
root = build_tree(values)
to_sum_tree(root)
print(*inorder(root))
