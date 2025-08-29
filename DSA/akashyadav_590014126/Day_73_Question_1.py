class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right

def sum_of_nodes(root):
    if root is None:
        return 0
    left_sum=sum_of_nodes(root.left)
    right_sum=sum_of_nodes(root.right)
    
    return root.val + left_sum + right_sum