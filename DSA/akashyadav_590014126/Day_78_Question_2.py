class Node:
    def __init__(self,val):
        self.val=val
        self.left=None
        self.right=None
def insertBST(root,key):
    if root is None:
        return Node(key)
    if key<root.val:
        root.left= insertBST(root.left)
    else:
        root.right=insertBST(root.right)
def inorderTraversal(root):
    if root:
        inorderTraversal(root.left)
        print(root.val,end=' ')
        inorderTraversal(root.right)
        