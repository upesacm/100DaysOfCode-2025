from collections import defaultdict, deque

class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert(root, val):
    if not root:
        return Node(val)
    if val < root.val:
        root.left = insert(root.left, val)
    else:
        root.right = insert(root.right, val)
    return root

def vertical_order(root):
    if not root:
        return []
    q = deque([(root, 0)])
    cols = defaultdict(list)
    while q:
        node, hd = q.popleft()
        cols[hd].append(node.val)
        if node.left:
            q.append((node.left, hd - 1))
        if node.right:
            q.append((node.right, hd + 1))
    return [cols[x] for x in sorted(cols.keys())]

n = int(input("Enter number of nodes: "))
arr = list(map(int, input("Enter values: ").split()))
root = None
for val in arr:
    root = insert(root, val)
print(vertical_order(root))
