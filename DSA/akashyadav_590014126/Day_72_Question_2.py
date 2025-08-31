class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right

def are_identical(root1,root2):
    if not root1 and not root2:
        return True
    if not root1 or root2:
        return False
    
    return (root1.val==root2.val and are_identical(root1.left,root2.left) and are_identical(root1.right,root2.right))