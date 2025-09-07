# Insert into BST
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

def inorder(root):
    return inorder(root.left) + [root.val] + inorder(root.right) if root else []

def insert(root, key):
    if not root: return Node(key)
    if key < root.val:
        root.left = insert(root.left, key)
    elif key > root.val:
        root.right = insert(root.right, key)
    return root

values = input().split()
key = int(input())
root = build_tree(values)
root = insert(root, key)
print(*inorder(root))
