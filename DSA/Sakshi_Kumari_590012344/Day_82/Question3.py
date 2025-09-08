class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def bstToGreater(root):
    s = 0
    def revInorder(n):
        nonlocal s
        if n is None:
            return
        revInorder(n.right)
        s += n.val
        n.val = s
        revInorder(n.left)
    revInorder(root)
    return root
