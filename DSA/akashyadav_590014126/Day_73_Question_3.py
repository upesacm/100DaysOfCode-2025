class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=0
        self.left=left
        self.right=right

def find_max(root):
    if root is None:
        return float('-inf')
    
    left_max=find_max(root.left)
    right_max=find_max(root.right)

    return max(root.val,left_max,right_max)