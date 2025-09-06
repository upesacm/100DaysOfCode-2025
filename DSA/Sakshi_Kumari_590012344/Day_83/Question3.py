class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None

def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.data:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    return root

def inorder(root, arr):
    if root:
        inorder(root.left, arr)
        arr.append(root.data)
        inorder(root.right, arr)

def twoSumBST(root, target):
    values = []
    inorder(root, values)
    i, j = 0, len(values) - 1
    while i < j:
        s = values[i] + values[j]
        if s == target:
            return True
        elif s < target:
            i += 1
        else:
            j -= 1
    return False
