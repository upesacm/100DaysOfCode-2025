class TreeNode:
    def __init__(self,val):
        self.val=val
        self.left=None
        self.right=None

def count_leaves(root):
    if root is None:
        return 0
    if root.left is None and root.right is None:
        return 1
    return count_leaves(root.left)+count_leaves(root.right)