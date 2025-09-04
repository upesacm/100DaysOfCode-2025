# Count Nodes in BST
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

def count_nodes(root):
    if not root: return 0
    return 1 + count_nodes(root.left) + count_nodes(root.right)

values = input().split()
root = build_tree(values)
print(count_nodes(root))
