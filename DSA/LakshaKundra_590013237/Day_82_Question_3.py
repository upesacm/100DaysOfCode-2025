class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def bst_to_greater(root):
    s = 0
    def traverse(node):
        nonlocal s
        if not node:
            return
        traverse(node.right)
        s += node.val
        node.val = s
        traverse(node.left)
    traverse(root)

def inorder(root):
    if root:
        inorder(root.left)
        print(root.val, end=" ")
        inorder(root.right)

root1 = Node(5)
root1.left = Node(2)
root1.right = Node(13)
bst_to_greater(root1)
inorder(root1)
print()

root2 = Node(2)
root2.left = Node(0)
root2.right = Node(3)
root2.left.left = Node(-4)
root2.left.right = Node(1)
bst_to_greater(root2)
inorder(root2)
