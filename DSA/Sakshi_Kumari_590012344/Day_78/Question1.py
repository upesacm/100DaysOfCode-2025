class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def search_bst(root, key):
    if root is None:
        return False
    if root.val == key:
        return True
    if key < root.val:
        return search_bst(root.left, key)
    else:
        return search_bst(root.right, key)
