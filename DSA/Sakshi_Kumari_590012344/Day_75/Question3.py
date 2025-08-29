class Node:
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None

def height(node):
    if node is None:
        return 0
    left_h = height(node.left)
    right_h = height(node.right)
    return 1 + max(left_h, right_h)

def diameter(root):
    if root is None:
        return 0
    left_d = diameter(root.left)
    right_d = diameter(root.right)
    left_h = height(root.left)
    right_h = height(root.right)
    through_root = left_h + right_h + 1
    return max(through_root, left_d, right_d)
