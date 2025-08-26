# Check if Two Trees are Identical
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

def identical(t1, t2):
    if not t1 and not t2: return True
    if not t1 or not t2: return False
    return t1.val == t2.val and identical(t1.left, t2.left) and identical(t1.right, t2.right)

tree1 = input().split()
tree2 = input().split()
t1 = build_tree(tree1)
t2 = build_tree(tree2)
print("Yes" if identical(t1, t2) else "No")
