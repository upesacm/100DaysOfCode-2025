class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def lca(root, p, q):
    while root:
        if p < root.val and q < root.val:
            root = root.left
        elif p > root.val and q > root.val:
            root = root.right
        else:
            return root.val

root = Node(6)
root.left = Node(2)
root.right = Node(8)
root.left.left = Node(0)
root.left.right = Node(4)
root.right.left = Node(7)
root.right.right = Node(9)
print(lca(root, 2, 8))

root2 = Node(6)
root2.left = Node(2)
root2.right = Node(8)
root2.left.left = Node(0)
root2.left.right = Node(4)
root2.right.left = Node(7)
root2.right.right = Node(9)
print(lca(root2, 2, 4))
