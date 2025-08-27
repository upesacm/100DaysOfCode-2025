from collections import deque

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def build_tree(values):
    if not values or values[0] == "None":
        return None
    nodes = [Node(int(v)) if v != "None" else None for v in values]
    kids = nodes[::-1]
    root = kids.pop()
    for node in nodes:
        if node:
            if kids: node.left = kids.pop()
            if kids: node.right = kids.pop()
    return root

def level_order(root):
    if not root:
        return []
    q = deque([root])
    result = []
    while q:
        node = q.popleft()
        result.append(str(node.value))
        if node.left: q.append(node.left)
        if node.right: q.append(node.right)
    return result

values = input("Enter tree nodes in level order (use None for empty): ").split()
tree = build_tree(values)
print(" ".join(level_order(tree)))
