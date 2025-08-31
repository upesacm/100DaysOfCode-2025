# Mirror of Binary Tree
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def mirror(node):
    if node:
        node.left, node.right = node.right, node.left
        mirror(node.left)
        mirror(node.right)

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

def inorder(node):
    return inorder(node.left) + [node.val] + inorder(node.right) if node else []

values = input().split()
root = build_tree(values)
mirror(root)
print(inorder(root))
