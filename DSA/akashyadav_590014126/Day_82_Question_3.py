class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def convertBST(root):
    total = 0

    def reverseInorder(node):
        nonlocal total
        if not node:
            return
        reverseInorder(node.right)
        total += node.val
        node.val = total
        reverseInorder(node.left)

    reverseInorder(root)
    return root

def inorderTraversal(root):
    if not root:
        return []
    return inorderTraversal(root.left) + [root.val] + inorderTraversal(root.right)
