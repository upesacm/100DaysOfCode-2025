# Check if Tree is Balanced
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

def check_balance(root):
    def dfs(node):
        if not node: return 0
        left = dfs(node.left)
        if left == -1: return -1
        right = dfs(node.right)
        if right == -1: return -1
        if abs(left - right) > 1: return -1
        return 1 + max(left, right)
    return dfs(root) != -1

values = input().split()
root = build_tree(values)
print("Yes" if check_balance(root) else "No")
