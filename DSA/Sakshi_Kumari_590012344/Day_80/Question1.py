class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert(root, val):
    if root is None:
        return Node(val)
    if val < root.val:
        root.left = insert(root.left, val)
    else:
        root.right = insert(root.right, val)
    return root

def findLCA(root, n1, n2):
    while root:
        if n1 < root.val and n2 < root.val:
            root = root.left
        elif n1 > root.val and n2 > root.val:
            root = root.right
        else:
            return root
