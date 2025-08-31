class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right

def mirror_tree(root):
    if root is None:
        return None
    
    root.left,root.right=root.right,root.left

    mirror_tree(root.left)
    mirror_tree(root.right)

    return root