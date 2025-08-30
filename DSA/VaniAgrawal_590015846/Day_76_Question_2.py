# Print Ancestors of a Node
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

def print_ancestors(root, target):
    if not root: return False
    if root.val == target:
        return True
    if print_ancestors(root.left, target) or print_ancestors(root.right, target):
        print(root.val, end=" ")
        return True
    return False

values = input().split()
target = int(input())
root = build_tree(values)
print_ancestors(root, target)
