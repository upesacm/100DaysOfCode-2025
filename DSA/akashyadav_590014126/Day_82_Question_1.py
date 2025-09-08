class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def sortedArrayToBST(arr):
    def buildBST(start, end):
        if start > end:
            return None
        mid = (start + end) // 2
        node = TreeNode(arr[mid])
        node.left = buildBST(start, mid - 1)
        node.right = buildBST(mid + 1, end)
        return node
    return buildBST(0, len(arr) - 1)

def preorderTraversal(root):
    if not root:
        return []
    return [root.val] + preorderTraversal(root.left) + preorderTraversal(root.right)
