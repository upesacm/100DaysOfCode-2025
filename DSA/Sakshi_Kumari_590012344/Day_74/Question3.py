class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def print_paths(root, path=[]):
    if root is None:
        return
    path = path + [root.data]
    if root.left is None and root.right is None:
        print(path)
    else:
        print_paths(root.left, path)
        print_paths(root.right, path)
