class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def countLeaves(root):
    if root is None:
        return 0
    if root.left is None and root.right is None:
        return 1
    return countLeaves(root.left) + countLeaves(root.right)

root1 = Node(1)
root1.left = Node(2)
root1.right = Node(3)
print(countLeaves(root1))

root2 = Node(10)
root2.right = Node(20)
root2.right.left = Node(15)
print(countLeaves(root2))
