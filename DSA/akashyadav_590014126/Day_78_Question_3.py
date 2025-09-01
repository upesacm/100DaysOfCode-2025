class Node:
    def _init__(self,val):
        self.val=val
        self.left=None
        self.right=None
def findmin(root):
    if root is None:
        return None
    while root.left:
        root=root.left
    return root.val
def findmax(root):
    if root is None:
        return None
    while root.right:
        root=root.right
    return root.val