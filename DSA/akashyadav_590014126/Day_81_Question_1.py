class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def rangeSumBST(root, L, R):
    if not root:
        return 0

    if root.val < L:
        return rangeSumBST(root.right, L, R)
    elif root.val > R:
        return rangeSumBST(root.left, L, R)
    else:
        return (root.val +
                rangeSumBST(root.left, L, R) +
                rangeSumBST(root.right, L, R))
