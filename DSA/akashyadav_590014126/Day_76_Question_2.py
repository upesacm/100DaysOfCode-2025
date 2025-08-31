class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

def print_ancestors(root, target):
    if root is None:
        return False

    if root.data == target:
        return True

    if print_ancestors(root.left, target) or print_ancestors(root.right, target):
        print(root.data, end=' ')
        return True

    return False
