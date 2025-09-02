# Print All Root to Leaf Paths
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

def all_paths(root, path, res):
    if not root: return
    path.append(str(root.val))
    if not root.left and not root.right:
        res.append("->".join(path))
    else:
        all_paths(root.left, path, res)
        all_paths(root.right, path, res)
    path.pop()

values = input().split()
root = build_tree(values)
res = []
all_paths(root, [], res)
for p in res:
    print(p)
