from collections import defaultdict, deque

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def verticalOrderTraversal(root):
    if not root:
        return []

    column_table = defaultdict(list)
    queue = deque([(root, 0)])  

    while queue:
        node, hd = queue.popleft()
        column_table[hd].append(node.val)
        if node.left:
            queue.append((node.left, hd - 1))
        if node.right:
            queue.append((node.right, hd + 1))

    return [column_table[x] for x in sorted(column_table)]
