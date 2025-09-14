# Convert BST to Greater Tree
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

def convert_greater_tree(root):
    total = 0
    def reverse_inorder(node):
        nonlocal total
        if not node: return
        reverse_inorder(node.right)
        total += node.val
        node.val = total
        reverse_inorder(node.left)
    reverse_inorder(root)

def inorder(root):
    return inorder(root.left) + [root.val] + inorder(root.right) if root else []

values = input().split()
root = build_tree(values)
convert_greater_tree(root)
print(*inorder(root))
