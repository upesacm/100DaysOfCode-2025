class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

def count_nodes_at_level(root, level):
    if root is None:
        return 0

    if level == 1:
        return 1

    left_count = count_nodes_at_level(root.left, level - 1)
    right_count = count_nodes_at_level(root.right, level - 1)

    return left_count + right_count
