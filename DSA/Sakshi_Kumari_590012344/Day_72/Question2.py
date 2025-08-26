class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def is_identical(root1, root2):
    if root1 is None and root2 is None:
        return True
    if root1 is None or root2 is None:
        return False
    return (root1.key == root2.key and 
            is_identical(root1.left, root2.left) and 
            is_identical(root1.right, root2.right))
