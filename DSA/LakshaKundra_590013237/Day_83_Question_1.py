from collections import defaultdict, deque

class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def vertical_order(root):
    if not root:
        return []
    q = deque([(root, 0)])
    col_map = defaultdict(list)
    while q:
        node, hd = q.popleft()
        col_map[hd].append(node.val)
        if node.left:
            q.append((node.left, hd - 1))
        if node.right:
            q.append((node.right, hd + 1))
    return [col_map[x] for x in sorted(col_map)]

root1 = Node(3)
root1.left = Node(9)
root1.right = Node(20)
root1.right.left = Node(15)
root1.right.right = Node(7)
print(vertical_order(root1))

root2 = Node(4)
root2.left = Node(2)
root2.right = Node(6)
root2.left.left = Node(1)
root2.left.right = Node(3)
root2.right.left = Node(5)
root2.right.right = Node(7)
print(vertical_order(root2))
