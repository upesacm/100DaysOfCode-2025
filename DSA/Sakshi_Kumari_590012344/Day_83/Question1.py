class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None

def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.data:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    return root

def verticalOrder(root):
    if root is None:
        return []

    q = [(root, 0)]
    mp = {}

    while q:
        node, hd = q.pop(0)

        if hd in mp:
            mp[hd].append(node.data)
        else:
            mp[hd] = [node.data]

        if node.left:
            q.append((node.left, hd - 1))
        if node.right:
            q.append((node.right, hd + 1))

    result = []
    for hd in sorted(mp.keys()):
        result.append(mp[hd])
    return result
