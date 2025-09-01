def tree_height(root):
    if root is None:
        return 0

    left_height = tree_height(root.left)
    right_height = tree_height(root.right)

    return 1 + max(left_height, right_height)
