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

def serialize(root):
    result = []
    def preorder(node):
        if not node:
            return
        result.append(str(node.data))
        preorder(node.left)
        preorder(node.right)
    preorder(root)
    return " ".join(result)

def deserialize(data):
    values = list(map(int, data.split()))
    index = [0]
    def build(min_val, max_val):
        if index[0] >= len(values):
            return None
        val = values[index[0]]
        if val < min_val or val > max_val:
            return None
        index[0] += 1
        node = Node(val)
        node.left = build(min_val, val)
        node.right = build(val, max_val)
        return node
    return build(float("-inf"), float("inf"))
