# Right View of Binary Tree
from collections import deque
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

def right_view(root):
    if not root: return []
    q = deque([root])
    res = []
    while q:
        n = len(q)
        for i in range(n):
            node = q.popleft()
            if i == n-1:
                res.append(node.val)
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
    return res

values = input().split()
root = build_tree(values)
print(*right_view(root))
