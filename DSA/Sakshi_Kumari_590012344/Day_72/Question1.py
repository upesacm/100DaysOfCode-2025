class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def mirror(root):
    if root is None:
        return None
    root.left, root.right = root.right, root.left
    mirror(root.left)
    mirror(root.right)
    return root
