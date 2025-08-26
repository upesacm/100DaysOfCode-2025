class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def height(root):
    if root is None:
        return 0
    return 1 + max(height(root.left), height(root.right))

root1 = Node(1)
root1.left = Node(2)
root1.left.left = Node(3)
print(height(root1))

root2 = Node(1)
root2.left = Node(2)
root2.right = Node(3)
print(height(root2))
