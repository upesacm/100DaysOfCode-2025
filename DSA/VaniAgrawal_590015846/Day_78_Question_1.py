# Search in BST
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

def search_bst(root, key):
    if not root: return False
    if root.val == key: return True
    if key < root.val:
        return search_bst(root.left, key)
    else:
        return search_bst(root.right, key)

values = input().split()
key = int(input())
root = build_tree(values)
print("Yes" if search_bst(root, key) else "No")
