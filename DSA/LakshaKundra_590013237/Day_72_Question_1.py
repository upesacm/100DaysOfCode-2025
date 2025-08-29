class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def mirror(root):
    if root is None:
        return None
    root.left, root.right = mirror(root.right), mirror(root.left)
    return root

def inorder(root):
    if root:
        inorder(root.left)
        print(root.key, end=" ")
        inorder(root.right)

# Example 1
root1 = Node(1)
root1.left = Node(2)
root1.right = Node(3)

print("Inorder before mirror:")
inorder(root1)
mirror(root1)
print("\nInorder after mirror:")
inorder(root1)

# Example 2
root2 = Node(4)
root2.left = Node(2)
root2.right = Node(7)
root2.left.left = Node(1)
root2.left.right = Node(3)
root2.right.left = Node(6)
root2.right.right = Node(9)

print("\n\nInorder before mirror:")
inorder(root2)
mirror(root2)
print("\nInorder after mirror:")
inorder(root2)
