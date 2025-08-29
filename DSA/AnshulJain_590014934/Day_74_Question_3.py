class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def print_paths(root, path):
    if root is None:
        return
    path.append(str(root.val))
    if root.left is None and root.right is None:
        print("->".join(path))
    else:
        print_paths(root.left, path)
        print_paths(root.right, path)
    path.pop()

def build_tree():
    from collections import deque
    vals = input().split()
    if not vals or vals[0] == 'N':
        return None
    root = Node(int(vals[0]))
    queue = deque([root])
    i = 1
    while queue and i < len(vals):
        curr = queue.popleft()
        if vals[i] != 'N':
            curr.left = Node(int(vals[i]))
            queue.append(curr.left)
        i += 1
        if i < len(vals) and vals[i] != 'N':
            curr.right = Node(int(vals[i]))
            queue.append(curr.right)
        i += 1
    return root

root = build_tree()
print_paths(root, [])
