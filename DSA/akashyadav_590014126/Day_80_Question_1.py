class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def lowestCommonAncestor(root, p, q):
    current = root
    while current:
        if p.val < current.val and q.val < current.val:
            current = current.left 
        elif p.val > current.val and q.val > current.val:
            current = current.right  
        else:
            return current 
