class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def find_min(root):
    while root and root.left:
        root = root.left
    return root.val if root else None

def find_max(root):
    while root and root.right:
        root = root.right
    return root.val if root else None
