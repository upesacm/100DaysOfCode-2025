class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def printNodesInRange(root, L, R):
    def inorder(node):
        if not node:
            return
        if node.val > L:
            inorder(node.left)
        if L <= node.val <= R:
            print(node.val, end=' ')
        if node.val < R:
            inorder(node.right)
    inorder(root)
