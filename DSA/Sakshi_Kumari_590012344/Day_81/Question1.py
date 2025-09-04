class TreeNode:
    def __init__(self, value):
        self.val = value
        self.left = None
        self.right = None

def range_sum_bst(root, L, R):
    if root is None:
        return 0
    if root.val < L:
        return range_sum_bst(root.right, L, R)
    if root.val > R:
        return range_sum_bst(root.left, L, R)
    return root.val + range_sum_bst(root.left, L, R) + range_sum_bst(root.right, L, R)
