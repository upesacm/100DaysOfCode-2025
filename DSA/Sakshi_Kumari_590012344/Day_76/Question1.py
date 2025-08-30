class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def to_sum_tree(root):
    if root is None:
        return 0
    left_sum = to_sum_tree(root.left)
    right_sum = to_sum_tree(root.right)
    old_value = root.value
    root.value = left_sum + right_sum
    return root.value + old_value
