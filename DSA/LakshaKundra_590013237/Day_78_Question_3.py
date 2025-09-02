class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def find_min(root):
    while root.left:
        root = root.left
    return root.key

def find_max(root):
    while root.right:
        root = root.right
    return root.key

root = Node(8)
root.left = Node(3)
root.right = Node(10)
root.left.left = Node(1)
root.left.right = Node(6)
root.right.right = Node(14)
print("Min =", find_min(root), ", Max =", find_max(root))

root = Node(5)
print("Min =", find_min(root), ", Max =", find_max(root))
