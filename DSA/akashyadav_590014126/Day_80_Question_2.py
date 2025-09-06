class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def deleteNode(root, key):
    if not root:
        return None

    if key < root.val:
        root.left = deleteNode(root.left, key)
    elif key > root.val:
        root.right = deleteNode(root.right, key)
    else:
        if not root.left and not root.right:
            return None
        if not root.left:
            return root.right
        if not root.right:
            return root.left
        successor = findMin(root.right)
        root.val = successor.val
        root.right = deleteNode(root.right, successor.val)
    return root

def findMin(node):
    while node.left:
        node = node.left
    return node

def inorderTraversal(root):
    return inorderTraversal(root.left) + [root.val] + inorderTraversal(root.right) if root else []
