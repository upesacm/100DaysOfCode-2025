class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def serialize(root):
    def preorder(node):
        if not node:
            return []
        return [str(node.val)] + preorder(node.left) + preorder(node.right)
    return ','.join(preorder(root))

def deserialize(data):
    if not data:
        return None
    values = list(map(int, data.split(',')))
    index = [0]

    def build(min_val, max_val):
        if index[0] == len(values):
            return None
        val = values[index[0]]
        if val < min_val or val > max_val:
            return None
        index[0] += 1
        node = TreeNode(val)
        node.left = build(min_val, val)
        node.right = build(val, max_val)
        return node

    return build(float('-inf'), float('inf'))

def inorderTraversal(root):
    if not root:
        return []
    return inorderTraversal(root.left) + [root.val] + inorderTraversal(root.right)
