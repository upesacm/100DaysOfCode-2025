# Diameter of Binary Tree
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

def diameter(root):
    ans = [0]
    def height(node):
        if not node: return 0
        l = height(node.left)
        r = height(node.right)
        ans[0] = max(ans[0], l + r)
        return 1 + max(l, r)
    height(root)
    return ans[0]

values = input().split()
root = build_tree(values)
print(diameter(root))
