class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def print_ancestors(root, target):
    if root is None:
        return False
    if root.value == target:
        return True
    if print_ancestors(root.left, target) or print_ancestors(root.right, target):
        print(root.value, end=" ")
        return True
    return False
