class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def kthSmallest(root, k):
    def inorder(node):
        if not node or result[0] is not None:
            return
        inorder(node.left)
        count[0] += 1
        if count[0] == k:
            result[0] = node.val
            return
        inorder(node.right)

    count = [0]
    result = [None]
    inorder(root)
    return result[0]
