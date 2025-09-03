class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert(root, data):
    if root is None:
        return Node(data)
    if data < root.data:
        root.left = insert(root.left, data)
    else:
        root.right = insert(root.right, data)
    return root

def inorderKth(root, k, count):
    if root is None:
        return None
    left = inorderKth(root.left, k, count)
    if left:
        return left
    count[0] += 1
    if count[0] == k:
        return root
    return inorderKth(root.right, k, count)

def kthSmallest(root, k):
    count = [0]
    return inorderKth(root, k, count)
