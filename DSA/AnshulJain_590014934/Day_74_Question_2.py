class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def is_balanced(root):
    def check(node):
        if node is None:
            return 0
        lh = check(node.left)
        if lh == -1:
            return -1
        rh = check(node.right)
        if rh == -1:
            return -1
        if abs(lh - rh) > 1:
            return -1
        return max(lh, rh) + 1
    return check(root) != -1

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
if is_balanced(root):
    print("Yes")
else:
    print("No")
