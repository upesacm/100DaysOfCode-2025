def helper(node):
    if not node:
        return 0

    # Ignore negative contributions
    left_sum = max(0, helper(node.left))
    right_sum = max(0, helper(node.right))

    # Max path including this node as highest point
    current_max = node.val + left_sum + right_sum
    self.max_path_sum = max(self.max_path_sum, current_max)

    # Return max path *extending to parent*
    return node.val + max(left_sum, right_sum)
