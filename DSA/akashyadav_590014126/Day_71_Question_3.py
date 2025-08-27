class TreeNode:
    def __init__(self,val):
        self.val=val
        self.left=None
        self.right=None
    
def tree_height(root):
    if root is None:
        return 0
    left_hight=tree_height(root.left)
    right_height=tree_height(root.right)
    return max(left_height,right_max) + 1