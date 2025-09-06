class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def checkBalanced(root):
    def height(n):
        if n is None:
            return 0
        l = height(n.left)
        if l == -1:
            return -1
        r = height(n.right)
        if r == -1:
            return -1
        if abs(l - r) > 1:
            return -1
        return max(l, r) + 1
    return height(root) != -1
