class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def count_nodes_at_level(root, level):
    if root is None:
        return 0
    if level == 1:
        return 1
    return count_nodes_at_level(root.left, level - 1) + count_nodes_at_level(root.right, level - 1)
