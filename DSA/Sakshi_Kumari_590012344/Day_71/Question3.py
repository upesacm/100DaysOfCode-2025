class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def height_of_tree(root):
    if root is None:
        return 0
    left_height = height_of_tree(root.left)
    right_height = height_of_tree(root.right)
    return max(left_height, right_height) + 1
