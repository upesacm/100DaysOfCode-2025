class TreeNode:
    def __init__(self,val):
        self.val=val
        self.left=None
        self.right=None

def inorderTraversal(root):
    result=[]

    def traversal(node):
        if not node:
            return 
        traversal(node.left)
        result.append(node.val)
        traversal(node.right)
    
    traversal(root)
    return result