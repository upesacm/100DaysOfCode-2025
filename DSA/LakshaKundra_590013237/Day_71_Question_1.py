class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def inorder(root):
    if root:
        inorder(root.left)
        print(root.val, end=" ")
        inorder(root.right)

root1 = Node(1)
root1.right = Node(3)
root1.right.left = Node(2)
inorder(root1)
print()

root2 = Node(4)
root2.left = Node(2)
root2.right = Node(5)
inorder(root2)
print()
