# Print Nodes at K Distance
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

def print_k_distance(root, k):
    if not root: return []
    if k == 0: return [root.val]
    return print_k_distance(root.left, k-1) + print_k_distance(root.right, k-1)

values = input().split()
k = int(input())
root = build_tree(values)
print(*print_k_distance(root, k))
