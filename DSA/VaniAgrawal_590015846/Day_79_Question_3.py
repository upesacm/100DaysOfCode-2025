# Check if Valid BST
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

def is_valid_bst(root, low=float("-inf"), high=float("inf")):
    if not root: return True
    if not (low < root.val < high): return False
    return is_valid_bst(root.left, low, root.val) and is_valid_bst(root.right, root.val, high)

values = input().split()
root = build_tree(values)
print("Yes" if is_valid_bst(root) else "No")
