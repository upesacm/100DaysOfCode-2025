# Range Sum of BST
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

def range_sum(root, L, R):
    if not root: return 0
    if root.val < L: return range_sum(root.right, L, R)
    if root.val > R: return range_sum(root.left, L, R)
    return root.val + range_sum(root.left, L, R) + range_sum(root.right, L, R)

values = input().split()
L, R = map(int, input().split())
root = build_tree(values)
print(range_sum(root, L, R))
