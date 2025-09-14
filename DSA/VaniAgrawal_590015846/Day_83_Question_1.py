# Vertical Order Traversal of BST
from collections import deque, defaultdict

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

def vertical_order(root):
    if not root: return []
    hd_map = defaultdict(list)
    queue = deque([(root, 0)])
    while queue:
        node, hd = queue.popleft()
        hd_map[hd].append(node.val)
        if node.left:
            queue.append((node.left, hd - 1))
        if node.right:
            queue.append((node.right, hd + 1))
    result = []
    for hd in sorted(hd_map.keys()):
        result.append(hd_map[hd])
    return result

values = input().split()
root = build_tree(values)
print(vertical_order(root))
