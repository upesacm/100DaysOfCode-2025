class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def range_sum_bst(root, L, R):
    if not root:
        return 0

    total = 0

    # Add current node if in range
    if L <= root.val <= R:
        total += root.val

    # Traverse left subtree only if current node's value > L
    if root.val > L:
        total += range_sum_bst(root.left, L, R)

    # Traverse right subtree only if current node's value < R
    if root.val < R:
        total += range_sum_bst(root.right, L, R)

    return total
