def convert_to_sum_tree(root):
    if root is None:
        return 0

    old_val = root.val

    left_sum = convert_to_sum_tree(root.left)
    right_sum = convert_to_sum_tree(root.right)

    # Node's value should be sum of left and right subtrees
    root.val = left_sum + right_sum

    # Return sum of current subtree including old value
    return root.val + old_val
