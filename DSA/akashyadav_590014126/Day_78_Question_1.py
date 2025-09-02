class Node:
    def __init__(self,val):
        self.val=val
        self.left=None
        self.right=None
def searchBST(root,key):
    if root is None:
        return False
    if root.val == key:
        return True
    if key<root.val:
        return searchBST(root.left,key)
    else:
        return searchBST(root.right,key)